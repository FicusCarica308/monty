#include "monty.h"
/**
 *inv_error - prints unknown op code error and exits program
 *@l_n: line number error occured on
 *@o_c: op_code double pointer (code, push_value) from file
 *@s: Stack head pointer for freeing
 *@l: Line that is allocated by getline
 *@f: File pointer(descriptor) for closure
 */
void inv_error(unsigned int l_n, char **o_c, stack_t **s, char *l, FILE *f)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", l_n, o_c[0]);
	free(l);
	free(o_c);
	fclose(f);
	free_stack(&*s);
	exit(EXIT_FAILURE);
}
/**
 *push_error - prints unknown push code error and exits program
 *@l_n: line number error occured on
 *@o_c: op_code double pointer (code, push_value) from file
 *@s: Stack head pointer for freeing
 *@l: Line that is allocated by getline
 *@f: File pointer(descriptor) for closure
 */
void push_error(unsigned int l_n, char **o_c, stack_t **s, char *l, FILE *f)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction usage: push integer", l_n);
	free(l);
	free(o_c);
	fclose(f);
	free_stack(&*s);
	exit(EXIT_FAILURE);
}
/**
 *free_error - frees all memory from program in the event of a op_code failure
 *@op_c: the op_code double list alloacted in the program
 *@stack: the stack head
 *@line: The line allocated by getline
 *@fd: file descriptor(pointer)
 */
void free_error(char **op_c, stack_t **stack, char *line, FILE *fd)
{
	free(line);
	free(op_c);
	fclose(fd);
	free_stack(&*stack);
	exit(EXIT_FAILURE);
}
