
#pragma once

typedef struct vec2_s {
    int x;
    int y;
} vec2_t;

typedef struct vec3_s {
    int x;
    int y;
    int z;
} vec3_t;

vec2_t *new_vec2(int x, int y);
