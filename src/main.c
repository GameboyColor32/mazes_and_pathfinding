#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "utils.h"
#include "maze.h"
#include "vec.h"
#include "stack.h"
#include "vector.h"

static inline int offset(int x, int y, vec2_t *coords, maze_t *maze)
{
    if (coords == NULL)
	return (-1);
    return ((coords->y + y) * maze->width + (x + coords->x));
}

void recursive_backtracking(maze_t *maze)
{
    stack_t *stack = new_stack();
    vector_t *neighbours = new_vector();
    vec2_t *vec = new_vec2(0, 0);
    int total;
    vec2_t *data;
    int val[4] = {NORTH_DIR, EAST_DIR, SOUTH_DIR, WEST_DIR};

    if (stack == NULL || neighbours == NULL || vec == NULL || push_stack(stack, vec) == false)
	return;
    neighbours->print = &print_node_int_vector;
    stack->print = &print_node_cell_stack;
    total = maze->width * maze->height;
    maze->tiles[maze->width] = VISITED;
    maze->visited_cells = 1;
    while (maze->visited_cells < total) {
	if ((data = (vec2_t *)peek_stack(stack)) == NULL)
	    continue;
	// North (y coord)
	if (data->y > 0 && (maze->tiles[offset(0, -1, data, maze)] & VISITED) == 0)
	    push_vector(neighbours, &val[NORTH_DIR]);
	// East
	if (data->x < maze->width - 1 && (maze->tiles[offset(1, 0, data, maze)] & VISITED) == 0)
	    push_vector(neighbours, &val[EAST_DIR]);
	// South
	if (data->y < maze->height - 1 && (maze->tiles[offset(0, 1, data, maze)] & VISITED) == 0)
	    push_vector(neighbours, &val[SOUTH_DIR]);
	// West
	if (data->x > 0 && (maze->tiles[offset(-1, 0, data, maze)] & VISITED) == 0)
	    push_vector(neighbours, &val[WEST_DIR]);
	if (neighbours->length) {
	    int next_cell_dir = *((int *)index_vector(neighbours, rand() % neighbours->length));

	    switch (next_cell_dir) {
	    case (NORTH_DIR):
		maze->tiles[offset(0, 0, data, maze)] |= NORTH;
		maze->tiles[offset(0, -1, data, maze)] |= VISITED | SOUTH;
		if ((vec = new_vec2(data->x + 0, data->y - 1)) == NULL)
		    return;
		push_stack(stack, vec);
		break;
	    case (EAST_DIR):
		maze->tiles[offset(+1, 0, data, maze)] |= VISITED | WEST;
		maze->tiles[offset(0, 0, data, maze)] |= EAST;
		if ((vec = new_vec2(data->x + 1, data->y + 0)) == NULL)
		    return;
		push_stack(stack, vec);
		break;
	    case (SOUTH_DIR):
		maze->tiles[offset(0, 0, data, maze)] |= SOUTH;
		maze->tiles[offset(0, +1, data, maze)] |= VISITED | NORTH;
		if ((vec = new_vec2(data->x + 0, data->y + 1)) == NULL)
		    return;
		push_stack(stack, vec);
		break;
	    case (WEST_DIR):
		maze->tiles[offset(-1, 0, data, maze)] |= VISITED | EAST;
		maze->tiles[offset(0, 0, data, maze)] |= WEST;
		if ((vec = new_vec2(data->x - 1, data->y + 0)) == NULL)
		    return;
		push_stack(stack, vec);
		break;
	    default:
		break;
	    }
	    maze->visited_cells += 1;
	} else {
	    free(pop_stack(&stack));
	}
	empty_vector(neighbours);
    }
    free_vector(&neighbours);
    free_vec_stack(&stack);
}

void final_maze(maze_t *maze)
{
    char *final_maze = calloc(1, sizeof(char) * ((maze->width * 2 + 1) * (maze->height * 2 + 1)));
    int w = maze->width * 2 + 1;

    if (final_maze == NULL)
	return;
    for (int y = 0; y < maze->height; y += 1) {
	for (int x = 0; x < maze->width; x += 1) {	
	    final_maze[((y * 2 + 1) * w) + (x * 2 + 1)] = 'x';
	    if (maze->tiles[y * maze->width + x] & WEST)
		final_maze[((y * 2 + 1) * w) + ((x - 1) * 2 + 1)] = 'x';
	    if (maze->tiles[y * maze->width + x] & SOUTH)
		final_maze[(((y + 1) * 2) * w) + (x * 2 + 1)] = 'x';
	    if (maze->tiles[y * maze->width + x] & EAST)
		final_maze[((y * 2 + 1) * w) + ((x + 1) * 2)] = 'x';	    
	    if (maze->tiles[y * maze->width + x] & NORTH)
		final_maze[(y * 2 * w) + (x * 2 + 1)] = 'x';
	}
    }
    for (int x = 0; x < w; x += 1) {
	for (int y = 0; y < maze->height * 2 + 1; y += 1) {
	    if (final_maze[y * w + x] == 'x')
		printf(".");
	    else if (final_maze[y * w + x] == 'o')
		printf(".");
	    else
		printf("#");
	}
	printf("\n");
    }
    free(final_maze);
}

int generate_maze(int w, int h)
{
    maze_t *maze = init_maze(w, h);

    if (maze == NULL)
	return (84);
    recursive_backtracking(maze);
    final_maze(maze);
    free_maze(maze);
    return (0);
}

int main(int ac, char **av)
{
    int w = 100;
    int h = 100;

    if (ac != 1) {
	if (ac == 2 && !strcmp(av[1], "-h")) {
	    printf("./maze [WIDTH] [HEIGHT]\n");
	    return (0);
	} else if (ac == 3) {
	    w = atoi(av[1]);
	    h = atoi(av[2]);
	} else
	    return (84);
    }
    srand(time(NULL));
    //test_list();
    //test_stack();
    generate_maze(w, h);
    return (0);
}
