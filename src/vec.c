
#include <stdio.h>
#include <stdlib.h>

#include "vec.h"

vec2_t *new_vec2(int x, int y)
{
    vec2_t *vec = malloc(sizeof(vec2_t));

    if (vec == NULL) {
	fprintf(stderr, "Malloc failed at %d::%s::%s\n", __LINE__, __FILE__, __func__);
        return (NULL);
    }
    vec->x = x;
    vec->y = y;
    return (vec);
}
