#include "monty.h"
/**
 *op_pint - he opcode pint prints the value at the top of the stack
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;

	temp_head = *stack;
	if (temp_head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		push_value = -1;
	}
	else
		printf("%d\n", temp_head->n);
}
