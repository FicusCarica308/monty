#include "monty.h"
/**
 *op_add - The opcode add adds the top two elements of the stack
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;

	temp_head = *stack;
	if (temp_head == NULL || temp_head->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		push_value = -1;
	}
	else
	{
		temp_head->next->n = temp_head->n + temp_head->next->n;
		op_pop(&*stack, line_number);
	}
}
/**
 *op_sub - The opcode sub subtracts the top two elements of the stack
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;

	temp_head = *stack;
	if (temp_head == NULL || temp_head->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		push_value = -1;
	}
	else
	{
		temp_head->next->n =  temp_head->next->n - temp_head->n;
		op_pop(&*stack, line_number);
	}
}
/**
 *op_mul - The opcode add adds the top two elements of the stack
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;

	temp_head = *stack;
	if (temp_head == NULL || temp_head->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		push_value = -1;
	}
	else
	{
		temp_head->next->n = temp_head->n * temp_head->next->n;
		op_pop(&*stack, line_number);
	}
}
/**
 *op_div - The opcode add adds the top two elements of the stack
 *@stack: head to current stack
 *@line_number: current line number
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_head;

	temp_head = *stack;
	if (temp_head == NULL || temp_head->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		push_value = -1;
	}
	else
	{
		if (temp_head->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			push_value = -1;
		}
		else
		{
			temp_head->next->n = temp_head->next->n / temp_head->n;
			op_pop(&*stack, line_number);
		}
	}
}
