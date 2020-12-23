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
/**
*
*
*/
void op_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp_head = *stack;
    (void)line_number;

	if (temp_head == NULL)
        putchar('\n');
    while (temp_head != NULL)
	{
         if (temp_head-> n > 127 || temp_head->n <= 0)
            {
                putchar('\n');
                break;
            }
        printf("%c", temp_head->n);
		temp_head = temp_head->next;
	}
    putchar('\n');
}