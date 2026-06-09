#include <stdlib.h>
#include "canvas.h"
#include "shapes.h"

/* ── Helpers ─────────────────────────────────────────────── */

static int abs_val(int x) { return x < 0 ? -x : x; }

/* ── Line: Bresenham's algorithm ─────────────────────────── */
void draw_line(int r1, int c1, int r2, int c2) {
    int dr = abs_val(r2 - r1);
    int dc = abs_val(c2 - c1);
    int sr = (r1 < r2) ? 1 : -1;
    int sc = (c1 < c2) ? 1 : -1;
    int err = dr - dc;

    while (1) {
        canvas_set(r1, c1, '*');
        if (r1 == r2 && c1 == c2) break;
        int e2 = 2 * err;
        if (e2 > -dc) { err -= dc; r1 += sr; }
        if (e2 <  dr) { err += dr; c1 += sc; }
    }
}

/* ── Rectangle ───────────────────────────────────────────── */
void draw_rectangle(int row, int col, int height, int width) {
    /* Top and bottom edges use '*', interior horizontal edges use '_' */
    for (int c = col; c < col + width; c++) {
        canvas_set(row, c, '_');               /* top */
        canvas_set(row + height - 1, c, '_'); /* bottom */
    }
    for (int r = row; r < row + height; r++) {
        canvas_set(r, col, '*');               /* left */
        canvas_set(r, col + width - 1, '*'); /* right */
    }
    /* Override corners with '*' */
    canvas_set(row,              col,             '*');
    canvas_set(row,              col + width - 1, '*');
    canvas_set(row + height - 1, col,             '*');
    canvas_set(row + height - 1, col + width - 1, '*');
}

/* ── Circle: Midpoint (Bresenham) circle algorithm ───────── */
/*
 * Because the terminal character cell is ~2x taller than wide,
 * we scale the column offset by 2 to get a rounder appearance.
 */
void draw_circle(int row, int col, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
        /* Plot 8 symmetric points; column scaled ×2 for aspect ratio */
        canvas_set(row - y, col + 2 * x, '*');
        canvas_set(row + y, col + 2 * x, '*');
        canvas_set(row - y, col - 2 * x, '*');
        canvas_set(row + y, col - 2 * x, '*');
        canvas_set(row - x, col + 2 * y, '*');
        canvas_set(row + x, col + 2 * y, '*');
        canvas_set(row - x, col - 2 * y, '*');
        canvas_set(row + x, col - 2 * y, '*');

        if (d < 0) d += 4 * x + 6;
        else { d += 4 * (x - y) + 10; y--; }
        x++;
    }
}

/* ── Triangle: three lines connecting three vertices ─────── */
void draw_triangle(int r1, int c1, int r2, int c2, int r3, int c3) {
    draw_line(r1, c1, r2, c2);
    draw_line(r2, c2, r3, c3);
    draw_line(r3, c3, r1, c1);
}
