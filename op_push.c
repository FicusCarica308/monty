#include "monty.h"
void op_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_head;
    (void)line_number;

        new_head = malloc(sizeof(stack_t));
        if (new_head == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        if (new_head != NULL)
        new_head->n = push_value;
        new_head->next = *stack;
        new_head->prev = NULL;
        if (*stack != NULL)
                (*stack)->prev = new_head;
        *stack = new_head;
}