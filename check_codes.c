#include "lists.h"
char *check_codes(char **op_codes)
{
    char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};
    char *code = NULL;
    int i = 0;
    int k = 0;

    for (k = 0; op_codes[k] != '\0'; k++)
    {
        for (i = 0; opcodes[i] != '\0'; i++)
        {
            code = strstr(op_codes[k], opcodes[i]);
            if (code != NULL)
            {
                free(op_codes[k]);
                op_codes[k] = malloc((strlen(code) + 1) * sizeof(char));
                strcpy(op_codes[k], code);
            }
        }
    }
    return (NULL);
}