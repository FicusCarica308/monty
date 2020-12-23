#include "monty.h"
/**
*
*
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
        stack_t *temp_head = *stack;

        if (temp_head == NULL)
        {
            fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
            push_value = -1;
        }
        else
        {
            if (temp_head-> n > 127 || temp_head->n < 0)
            {
                fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
                push_value = -1;
            }
            else
            {
                printf("%c\n", temp_head->n);
            }
        }
}