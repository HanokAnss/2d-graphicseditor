#include <stdio.h>
#include "canvas.h"

char canvas[ROWS][COLS];

/* Fill every cell with a space */
void canvas_init(void) {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            canvas[r][c] = ' ';
}

void canvas_clear(void) {
    canvas_init();
}

/* Print the full canvas row by row with a border */
void canvas_display(void) {
    /* Top border */
    printf("+");
    for (int c = 0; c < COLS; c++) printf("-");
    printf("+\n");

    for (int r = 0; r < ROWS; r++) {
        printf("|");
        for (int c = 0; c < COLS; c++)
            putchar(canvas[r][c]);
        printf("|\n");
    }

    /* Bottom border */
    printf("+");
    for (int c = 0; c < COLS; c++) printf("-");
    printf("+\n");
}

/* Safely set a pixel only if it's inside the canvas */
void canvas_set(int row, int col, char ch) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
        canvas[row][col] = ch;
}
