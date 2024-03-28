#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <math.h>

/**
 * check_char - Checks space for block.
 * @column: Is the column.
 * @row: Is the row.
 *
 * Return: # or space.
 */
char check_char(int column, int row);

/**
 * menger - Function that draws a 2D Menger Sponge.
 * @level: Is the level of the Menger Sponge to draw.
 *
 * Return: Void.
 */
void menger(int level);

#endif