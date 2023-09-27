#pragma once

#include "node.h"
#include "bool.h"

typedef struct vector_s vector_t;

typedef struct vector_s {
    int length;

    void (*print)(const vector_t *this);

    node_t *head;
} vector_t;

vector_t *new_vector(void);
void free_vector(vector_t **vector);
void empty_vector(vector_t *vector);
bool push_vector(vector_t *this, void *data);
void *index_vector(vector_t *this, int index);
