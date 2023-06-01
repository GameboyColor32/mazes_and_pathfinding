#include <stdlib.h>
#include <stdio.h>

#include "maze.h"

maze_t *init_maze(int w, int h)
{
    maze_t *maze = malloc(sizeof(maze_t));

    if (maze == NULL) {
	fprintf(stderr, "Malloc failed at %d::%s::%s\n", __LINE__, __FILE__, __func__);
	return (NULL);
    }
    if ((maze->tiles = calloc(1, sizeof(char) * (w * h))) == NULL) {
	fprintf(stderr, "Malloc failed at %d::%s::%s\n", __LINE__, __FILE__, __func__);
	return (NULL);
    }
    maze->width = w;
    maze->height = h;
    maze->visited_cells = 0;
    return (maze);
}

void print_maze(maze_t *maze)
{
    for (int x = 0; x < maze->width; x += 1) {
	for (int y = 0; y < maze->height; y += 1) {
	    if (maze->tiles[y * maze->width + x] & WALL)
		printf("#");
	    else if (maze->tiles[y * maze->width + x] & VISITED)
		printf("o");
	    else
		printf(".");
	}
	printf("\n");
    }
}

void free_maze(maze_t *maze)
{
    free(maze->tiles);
    free(maze);
}
