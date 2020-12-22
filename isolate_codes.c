#include "lists.h"
/**
 *check_number
 */
int check_number(char *push_num)
{
    int number = atoi(push_num);

    if (strcmp(push_num, "0") != 0 && number == 0)
        return (-1);
    else
        return (0);
}
/**
 *isolate_codes - isolates the opcode to be executed
 *@op_codes: our opcode argument list
 */
void isolate_codes(char **op_codes)
{
	char *hold = NULL, *code = NULL, *push_num = NULL;
	int k = 0;

	for (k = 0; op_codes[k] != '\0'; k++)
	{
		hold = malloc((strlen(op_codes[k]) + 1) * sizeof(char));
		if (hold == NULL)
            errors("malloc", 0, NULL, op_codes);
		strcpy(hold, op_codes[k]);
		code = strtok(hold, " ");
		if (strcmp(code, "push") == 0 || strcmp(code, "push\n") == 0)
		{
			push_num = strtok(NULL, " ");
			if (push_num != NULL && check_number(push_num) != -1)
				push_value = atoi(push_num);
			else
            {
                free(hold);
				errors("push", k + 1, op_codes[k], op_codes);
            }
            printf("push_val: %d\n", push_value);
			printf("next -- %s -- %s\n", code, push_num);
		}
		else
			printf("next -- %s\n", code);
		free(hold);
	}
}
