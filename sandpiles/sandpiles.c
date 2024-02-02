#include "sandpiles.h"
/**
 * sandpiles_sum - Function that computes the sum of two sandpiles :
 * Prototype: void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
 * That both grid1 and grid2 are individually stable
 * A sandpile is considered stable when none of its cells
 * contains more than 3 grains
 * When the function is done, grid1 must be stable
 * grid1 must be printed before each toppling round,
 * only if it is unstable (See example)
 * @grid1: first sandpile
 * @grid2: second sandpile
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;

	/* ADD SANDPILES */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = (grid1[i][j] > 3);
			unstable += (grid1[i][j] > 3);
		}

	/* STABILIZE SANDPILE */
	while (unstable)
	{
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid2[i][j])
				{
					grid1[i][j] -= 4;
					if (i + 1 < 3)
						grid1[i + 1][j] += 1;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j + 1 < 3)
						grid1[i][j + 1] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
				}

		/* re-count and re-map unstable cells */
		for (unstable = 0, i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid2[i][j] = (grid1[i][j] > 3);
				unstable += (grid1[i][j] > 3);
			}
	}
}

/**
 * print_grid - prints a grid of numbers
 * @grid: grid
 **/
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}