#include "lists.h"
void op_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_head;
    (void)line_number;

        new_head = malloc(sizeof(stack_t));
    /*print error for malloc fail here*/
        new_head->n = push_value;
        new_head->next = *stack;
        new_head->prev = NULL;
        if (*stack != NULL)
                (*stack)->prev = new_head;
        *stack = new_head;
}