#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "stack.h"
#include "vec.h"

void print_node_cell_vector(const vector_t *this)
{
    node_t *tmp = this->head;

    printf("Vector: %d\n", this->length);
    while (tmp) {
	printf("[(%d, %d)]->", ((vec2_t *) (tmp->data))->x, ((vec2_t *) (tmp->data))->x);
        tmp = tmp->next;
    }
    printf("[NULL]\n");
}

void print_node_int_vector(const vector_t *this)
{
    node_t *tmp = this->head;

    printf("Vector: %d\n", this->length);
    while (tmp) {
	printf("[%d]->", *((int *) (tmp->data)));
        tmp = tmp->next;
    }
    printf("[NULL]\n");
}

void print_node_cell_stack(const stack_t *this)
{
    node_t *tmp = this->head;

    while (tmp) {
	printf("[(%d, %d)]->", ((vec2_t *) (tmp->data))->x, ((vec2_t *) (tmp->data))->y);
        tmp = tmp->next;
    }
    printf("[NULL]\n");
}

void free_vec_stack(stack_t **stack)
{
    void *data;

    while ((data = pop_stack(stack)) != NULL)
	free(data);
    free_stack(stack);
}
