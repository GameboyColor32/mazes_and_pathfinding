#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node_t *new_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL) {
        fprintf(stderr, "Malloc failed at %d::%s::%s\n", __LINE__, __FILE__, __func__);
        return (NULL);
    }
    node->data = data;
    node->next = NULL;
    return (node);
}
