#include <stdlib.h>
#include "main.h"
/**
 * free_grid - frees a 2D grid created by the alloc_grid function
 * @grid: 2D grid to be freed
 * @height: height of the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
