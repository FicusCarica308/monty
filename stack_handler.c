#include "monty.h"
/**
 *get_op_func - will find which function to return depending on a given
 * operator
 *@s: this is the given operator character
 *Return: returns a pointer to the needed operation
 */
 void (*get_op_func(char *op_code))(stack_t **, unsigned int)
{
        instruction_t ops[] = {
                {"push", op_push},
                {"pall", op_pall},
                {"nop", NULL},
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
void *stack_handler(char **op_code, unsigned int line_n, stack_t **stack)
{
    void (*code_func)(stack_t **, unsigned int);

    if (op_code[1] != NULL)
        push_value = atoi(op_code[1]);
    code_func = get_op_func(op_code[0]);

    if (code_func == NULL)
        return (NULL);
    (*code_func)(&*stack, line_n);
    return (op_code);
}