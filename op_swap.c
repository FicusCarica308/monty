#include "monty.h"
/**
 *op_swap - The opcode swap swaps the top two elements of the stack.
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;
	int hold = 0;
	int hold2 = 0;

	temp_head = *stack;
	if (temp_head == NULL || temp_head->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		push_value = -1;
	}
	else
	{
		hold = temp_head->next->n;
		hold2 = temp_head->n;
		temp_head->next->n = hold2;
		temp_head->n = hold;
	}
}
