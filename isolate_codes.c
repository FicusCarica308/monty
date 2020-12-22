#include "lists.h"
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
		/*check if memory couldnt be malloced*/
		strcpy(hold, op_codes[k]);
		code = strtok(hold, " ");
		if (strcmp(code, "push") == 0)
		{
			push_num = strtok(NULL, " ");
			if (push_num != NULL)
				push_value = atoi(push_num);
			else
				printf("no value passed to push line number %d\n", k + 1);
			printf("next -- %s -- %s\n", code, push_num);
		}
		else
			printf("next -- %s\n", code);
		free(hold);
	}
}
