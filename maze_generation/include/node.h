#pragma once

typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

node_t *new_node(void *data);
