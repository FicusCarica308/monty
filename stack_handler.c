#include "monty.h"
int atoi_check(char *num)
{
        if (num == NULL)
                return (-1);
        if ((atoi(num) == 0 && strcmp(num, "0") != 0))
                return (-1);
        else
                return (atoi(num));
}
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
                {"pint", op_pint},
                {"pop", op_pop},
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
int stack_handler(char **op_code, unsigned int line_n, stack_t **stack)
{
    void (*code_func)(stack_t **, unsigned int);


    if (strcmp(op_code[0], "push") == 0)
    {
            if (atoi_check(op_code[1]) != -1)
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