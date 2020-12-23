#include "monty.h"
/**
 *atoi_check - checks if atoi is a number/is not null
 *@num: string with number
 *Return: returns the number or -1 on failure
 */
char *atoi_check(char *num)
{
	int i = 0;

	if (num == NULL)
		return ("False");
	for (i = 0; num[i]; i++)
		if (isdigit(num[i]) == 0 && num[i] != '-')
			return ("False");
	return (num);
}
/**
 *get_op_func - will find which function to return depending on a given
 * operator
 *@op_code: the current given opcode on the stack
 *Return: returns a pointer to the needed operation
 */
void (*get_op_func(char *op_code))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"add", op_add},
		{"swap", op_swap},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{NULL, NULL}
	};

	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(op_code, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
/**
 *stack_handler - handler all stack operations and op_code operations
 *@op_code: current op_code on the stack
 *@line_n: the current line number
 *@stack: the head of the stack list
 *Return: returns negative numbers if failure occurs and 0 if not
 */
int stack_handler(char **op_code, unsigned int line_n, stack_t **stack)
{
	void (*code_func)(stack_t **, unsigned int);

	if (strcmp(op_code[0], "push") == 0)
	{
		if (strcmp(atoi_check(op_code[1]), "False") != 0)
			push_value = atoi(op_code[1]);
		else
/*-2 stands for push error*/
			return (-2);
	}
	if (strcmp(op_code[0], "nop") == 0)
		return (0);
	code_func = get_op_func(op_code[0]);

	if (code_func == NULL)
		/*-3 stands for not a op_code error*/
		return (-3);
	(*code_func)(&*stack, line_n);
	if (push_value == -1)
		/*-1 id everything else*/
		return (-1);
	return (0);
}
