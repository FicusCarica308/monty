#include "monty.h"
void op_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp_head;
    (void)line_number;

     temp_head = *stack;

    while (temp_head != NULL)
    {
        printf("%d\n", temp_head->n);
        temp_head = temp_head->next;
    }
}