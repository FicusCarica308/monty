#include "monty.h"
void free_stack(stack_t **stack)
{
	stack_t *free_head;

	while (*stack != NULL)
	{
		free_head = *stack;
		*stack = (*stack)->next;
		free(free_head);
	}
}