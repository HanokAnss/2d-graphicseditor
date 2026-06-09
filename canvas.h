#ifndef CANVAS_H
#define CANVAS_H

#define ROWS 24
#define COLS 80

/* The 2D canvas stored as a character array */
extern char canvas[ROWS][COLS];

void canvas_init(void);
void canvas_display(void);
void canvas_clear(void);
void canvas_set(int row, int col, char ch);

#endif
