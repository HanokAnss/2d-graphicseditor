#ifndef SHAPES_H
#define SHAPES_H

/*
 * All draw functions use '*' for borders and '_' for horizontal fills.
 * row/col are 0-based coordinates on the canvas.
 */

void draw_line(int r1, int c1, int r2, int c2);
void draw_rectangle(int row, int col, int height, int width);
void draw_circle(int row, int col, int radius);
void draw_triangle(int r1, int c1, int r2, int c2, int r3, int c3);

#endif
