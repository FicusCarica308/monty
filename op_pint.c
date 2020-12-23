#include "monty.h"
void op_pint(stack_t **stack, unsigned int line_number)
{
    stack_t *temp_head;
    (void)line_number;

    temp_head = *stack;
    if (temp_head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		push_value = -1;
	}
    else
        printf("%d\n", temp_head->n);
}