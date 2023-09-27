#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

#include "vec.h"

void default_print(const vector_t *this)
{
    node_t *tmp = this->head;
    int i = 0;

    while (tmp) {
	printf("[%d]->", i);
	i += 1;
	tmp = tmp->next;
    }
    printf("[NULL]\n");
}

bool push_vector(vector_t *this, void *data)
{
    node_t *node = new_node(data);
    node_t *tmp;

    if (node == NULL)
	return (false);
    this->length += 1;
    if (this->head == NULL) {
	this->head = node;
	return (true);
    }
    tmp = this->head;
    while (tmp->next != NULL)
	tmp = tmp->next;
    tmp->next = node;
    return (true);
}

vector_t *new_vector(void)
{
    vector_t *vector = malloc(sizeof(vector_t));

    if (vector == NULL) {
	fprintf(stderr, "Malloc failed at %d::%s::%s\n", __LINE__, __FILE__, __func__);
	return (NULL);
    }
    vector->print = &default_print;
    vector->length = 0;
    vector->head = NULL;
    return (vector);
}

void free_vector(vector_t **vector)
{
    node_t *tmp;

    while ((*vector)->head != NULL) {
	tmp = (*vector)->head->next;
	free((*vector)->head);
	(*vector)->head = tmp;
    }
    free(*vector);
    *vector = NULL;
}

void empty_vector(vector_t *vector)
{
    node_t *tmp;

    while (vector->head != NULL) {
        tmp = vector->head->next;
        free(vector->head);
        vector->head = tmp;
    }
    vector->head = NULL;
    vector->length = 0;
}

void *index_vector(vector_t *this, int index)
{
    node_t *tmp;
    int i;

    if (this->head == NULL || index < 0 || index > this->length)
	return (NULL);
    tmp = this->head;
    i = 0;
    while (i < index) {
	tmp = tmp->next;
	i += 1;
    }
    return (tmp ? tmp->data : NULL);
}
