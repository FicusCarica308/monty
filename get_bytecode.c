#include "monty.h"
/**
 *get_code - retrieves the op_code and its value from the line
 *@line: the line from getline(file)
 *Return: returns a string array with op_code in idx 0 and push_val in idx 1
 */
char **get_code(char *line)
{
	char *code = NULL, *new_ele = NULL, **op_code = NULL;
	int i = 0;
	(void)i;

	op_code = malloc(sizeof(char *) * 3);
	if (op_code == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	code = strtok(line, " ");
	for (i = 0; code[i]; i++)
		if (code[i] == '\n')
			code[i] = '\0';
	if (strcmp("push", code) == 0)
	{
		new_ele = strtok(NULL, " ");
		if (new_ele != NULL)
			for (i = 0; new_ele[i]; i++)
				if (new_ele[i] == '\n')
					new_ele[i] = '\0';
	}
	if (code[0] == '\0')
		op_code[0] = "nop";
	else
		op_code[0] = code;
	if (new_ele != NULL && new_ele[0] == '\0')
		op_code[1] = NULL;
	else
		op_code[1] = new_ele;
	op_code[2] = NULL;
	return (op_code);
}
/**
*get_bytecodes - Retrieves bytecodes from a given file
*@file_name: a string contaning our file name or directory path
*/
void get_bytecodes(char *file_name)
{
	FILE *fp;
	char *line = NULL;
	char **op_code = NULL;
	size_t len = 0;
	int read_chars;
	unsigned int line_num = 1;
	stack_t *stack = NULL;
	int check = 0;
	(void)read_chars;

	fp = fopen(file_name, "r");

	while ((read_chars = getline(&line, &len, fp)) != -1)
	{
		op_code = get_code(line);
		check = stack_handler(op_code, line_num, &stack);
		if (check < 0)
		{
			if (check == -3)
				inv_error(line_num, op_code, &stack, line, fp);
			if (check == -2)
				push_error(line_num, op_code, &stack, line, fp);
			if (check == -1)
				free_error(op_code, &stack, line, fp);
		}
		line_num++;
		free(op_code);
	}
	free_stack(&stack);
	free(line);
	fclose(fp);
}
