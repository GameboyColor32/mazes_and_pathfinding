
#pragma once

#define WALL 0x1
#define VISITED 0x2
#define NORTH 0x4
#define EAST 0x8
#define SOUTH 0x10
#define WEST 0x20

#define NORTH_DIR 0
#define EAST_DIR 1
#define SOUTH_DIR 2
#define WEST_DIR 3

typedef struct maze_s {
    int width;
    int height;
    int visited_cells;
    char *tiles;
} maze_t;

maze_t *init_maze(int w, int h);
void print_maze(maze_t *maze);
void free_maze(maze_t *maze);
