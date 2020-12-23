#include "monty.h"
/**
 *op_pall - The opcode pall prints all the values on the stack,
 *starting from the top of the stack.
 *@stack: head to current stack
 *@line_number: current line number
 */
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
#include "monty.h"
/**
 *op_pop - The opcode pop removes the top element of the stack
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;

	temp_head = *stack;
	if (temp_head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		push_value = -1;
	}
	else
	{
		if (temp_head->next != NULL)
			temp_head->next->prev = NULL;
		*stack = temp_head->next;
		free(temp_head);
	}
}
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
		exit(EXIT_FAILURE);
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
