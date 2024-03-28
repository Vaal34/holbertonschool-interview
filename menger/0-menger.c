#include <stdio.h>
#include <math.h>

void drawMenger(int level, int x, int y, int size) {
    if (level == 0) {
        printf("#");
        return;
    }
    int newSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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
    int size = pow(3, level);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            drawMenger(level, i, j, size);
        }
        printf("\n");
    }
}