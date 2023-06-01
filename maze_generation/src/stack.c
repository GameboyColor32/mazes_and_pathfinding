
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "maze.h"
#include "vec.h"

bool push_stack(stack_t *stack, void *data)
{
    node_t *node = new_node(data);

    if (node == NULL)
        return (false);
    stack->length += 1;
    if (stack->head == NULL) {
        stack->head = node;
        return (true);
    }
    node->next = stack->head;
    stack->head = node;
    return (true);
}

void print_stack(const stack_t *this)
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

stack_t *new_stack(void)
{
    stack_t *stack = malloc(sizeof(stack_t));

    if (stack == NULL) {
	fprintf(stderr, "Malloc failed at %d::%s::%s\n", __LINE__, __FILE__, __func__);
        return (NULL);
    }
    stack->length = 0;
    stack->print = &print_stack;
    stack->head = NULL;
    return (stack);
}

void *pop_stack(stack_t **stack)
{
    node_t *tmp;
    void *data;

    if ((*stack)->head == NULL)
        return (NULL);
    tmp = (*stack)->head;
    data = (*stack)->head->data;
    (*stack)->head = tmp->next;
    free(tmp);
    (*stack)->length -= 1;
    return (data);
}

void *peek_stack(stack_t *stack)
{
    if (stack->head == NULL)
	return (NULL);
    return (stack->head->data);
}

void free_stack(stack_t **stack)
{
    node_t *tmp;

    while ((*stack)->head != NULL) {
        tmp = (*stack)->head->next;
        free((*stack)->head);
        (*stack)->head = tmp;
    }
    free(*stack);
    *stack = NULL;
}

void empty_stack(stack_t *stack)
{
    node_t *tmp;

    while (stack->head != NULL) {
        tmp = stack->head->next;
	free(stack->head->data);
        free(stack->head);
        stack->head = tmp;
    }
    stack->length = 0;
    stack->head = NULL;
}
