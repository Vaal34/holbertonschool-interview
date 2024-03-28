#include <stdio.h>
#include <math.h>

void drawMenger(int level, int x, int y, int size) {
    int i, j; // Declaring variables at the beginning of the block
    if (level == 0) {
        printf("#");
        return;
    }
    int newSize = size / 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                printf(" ");
            else
                drawMenger(level - 1, x + i * newSize, y + j * newSize, newSize);
        }
    }
}

void menger(int level) {
    if (level < 0)
        return;
    int i, j; // Declaring variables at the beginning of the block
    int size = (int)pow(3, level);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            drawMenger(level, i, j, size);
        }
        printf("\n");
    }
}
