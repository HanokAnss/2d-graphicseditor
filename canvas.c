#include <stdio.h>
#include "canvas.h"

char canvas[ROWS][COLS];

void canvas_init(void){
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            canvas[r][c]=' ';
        }
    }
}
void canvas_clear(void){
    canvas_init();
}

void canvas_display(void){
    printf("+");
    for (int c = 0; c < COLS; c++){
        printf("-");
        printf("+\n");
    }
}

for (int r = 0; r < ROWS; r++){
    printf("|");
    for (int c = 0; c < COLS; c++){
        putchar(canvas[r][c]);
    }
    printf("|\n");
}

printf("+");
for (int c = 0; c < COLS;c++){
    printf("-");
    printf("+\n");
}

void canvas_set(int row, int col, char ch){
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS){
        canvas[row][col]=ch;
    }
}