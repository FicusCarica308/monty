#include "monty.h"
void invalid_error(unsigned int line_n, char **op_c, stack_t **stack, char *line, FILE *fd)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", line_n, op_c[0]);
    free(line);
    free(op_c);
    fclose(fd);
    free_stack(&*stack);
    exit(EXIT_FAILURE);
}
void push_error(unsigned int line_n, char **op_c, stack_t **stack, char *line, FILE *fd)
{
    fprintf(stderr, "L%u: unknown instruction usage: push integer", line_n);
    free(line);
    free(op_c);
    fclose(fd);
    free_stack(&*stack);
    exit(EXIT_FAILURE);
}