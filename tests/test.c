void test_stack(void)
{
    stack_t *stack = new_stack();

    if (stack == NULL)
        return;
    stack->print = &print_node_cell_stack;
    vec2_t a = {1,1};
    vec2_t b = {2,2};
    vec2_t c = {3,3};

    if ((push_stack(stack, &a)) == false)
        return;
    if ((push_stack(stack, &b)) == false)
        return;
    if ((push_stack(stack, &c)) == false)
        return;
    stack->print(stack);
    pop_stack(&stack);
    stack->print(stack);
    free_stack(&stack);
}

void test_list(void)
{
    vector_t *list = new_vector();

    if (list == NULL)
        return;
    list->print = &print_node_cell_vector;
    vec2_t a = {1,1};
    vec2_t b = {2,2};
    vec2_t c = {3,3};

    if ((push_vector(list, &a)) == false)
        return;
    if ((push_vector(list, &b)) == false)
        return;
    if ((push_vector(list, &c)) == false)
        return;
    list->print(list);
    printf("uwu %d\n", ((vec2_t *)index_vector(list, 2))->x);
    free_vector(&list);
}
