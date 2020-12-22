#include "lists.h"
void errors(char *type, unsigned int lineNum, char *line, char **op_codes)
{
    (void)lineNum;
    (void)line;
    /*malloc errors*/
    if (strcmp(type, "malloc") == 0)
    {
        free_opcodes(op_codes);
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    /*invalid opcode*/
    if (strcmp(type, "invalid") == 0)
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", lineNum, line);
        free_opcodes(op_codes);
        exit(EXIT_FAILURE);
    }
    /*invalid push*/
    if (strcmp(type, "push") == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", lineNum);
        free_opcodes(op_codes);
        exit(EXIT_FAILURE);
    }

}