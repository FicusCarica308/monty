#include "lists.h"
/**
 *rm_excess - this function turns any spaced or new lines into nop codes
 *@op_codes: our unedited line input from get_opcodes
 *Return: returns a cleaner argument list without new lines or empty ones
 */
char **rm_excess(char **op_codes)
{
	int i = 0;
	int k = 0;
	int check = 0;
	char *nop = "nop";

	for (i = 0; op_codes[i] != '\0'; i++)
	{
		check = 0;
		if (op_codes[i][0] == '\n')
		{
			free(op_codes[i]);
			op_codes[i] = malloc((strlen(nop) + 1) * sizeof(char));
			if (op_codes[i] == NULL)
				errors("malloc", 0, NULL, op_codes);
			strcpy(op_codes[i], nop);
			continue;
		}
		for (k = 0; op_codes[i][k] != '\0'; k++)
		{
			if (op_codes[i][k] != ' ' && op_codes[i][k] != '\n')
			{
				check = 1;
			}
		}
		if (check == 0)
		{
			free(op_codes[i]);
			op_codes[i] = malloc((strlen(nop) + 1) * sizeof(char));
			if (op_codes[i] == NULL)
				errors("malloc", 0, NULL, op_codes);
			strcpy(op_codes[i], nop);
		}
	}
	return (op_codes);
}
