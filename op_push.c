#include "monty.h"
/**
 *op_push - The opcode push pushes an element to the stack.
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_head;
	(void)line_number;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		push_value = -1;
	}
	else
	{
		new_head->n = push_value;
		new_head->next = *stack;
		new_head->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = new_head;
		*stack = new_head;
/*sets push_value to 0 so we dont have any*/
/*overlapping values when checking errors*/
		push_value = 0;
	}
}
