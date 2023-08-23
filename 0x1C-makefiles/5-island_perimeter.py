#!/usr/bin/python3
""" funct to return perimeter of an island """


def island_perimeter(grid):
    """ Calculate perimeter of the island """
    rows = len(grid)
    if rows == 0:
        return 0
    cols = len(grid[0])
    per = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                per += 4
                if row > 0 and grid[row - 1][col] == 1:
                    per -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    per -= 2
    return per
