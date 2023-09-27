
#pragma once

#include "node.h"
#include "bool.h"

typedef struct stack_s stack_t;

typedef struct stack_s {
    int length;

    void (*print)(const stack_t *this);

    node_t *head;
} stack_t;

stack_t *new_stack(void);
void free_stack(stack_t **stack);
bool push_stack(stack_t *stack, void *data);
void empty_stack(stack_t *stack);
void *pop_stack(stack_t **stack);
void *peek_stack(stack_t *stack);
