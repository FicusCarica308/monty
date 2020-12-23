#include "monty.h"
/**
 *free_stack - frees all allocated stack memory
 *@stack: head to current stack list
 */
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
