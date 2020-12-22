#include "lists.h"
/**
 *free_opcodes - frees our opcode argument list
 *@op_codes: array of strings to be freed
 */
void free_opcodes(char **op_codes)
{
	int i = 0;

	for (i = 0; op_codes[i] != '\0'; i++)
	{
		printf("[%d] %s\n", i, op_codes[i]);
		free(op_codes[i]);
	}
	free(op_codes);
}
/**
 *main - this is our main function for our monty interpretor
 *@av: our agrument list from stream
 *@ac: our argument count from stream
 *Return: returns 0 on succesful completion exits with failure if not
 */
int main(int ac, char **av)
{
	char **op_codes;

	/*checks if arg count is proper amount and file exists*/
	if (ac != 2 || access(av[1], F_OK) != 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*checks if file can be read (make a seperaret open check)*/
	if (access(av[1], R_OK) != 0)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", av[1]);
		exit(EXIT_FAILURE);
	}
	op_codes = get_bytecodes(av[1]);
	rm_excess(op_codes);
	isolate_codes(op_codes);
	free_opcodes(op_codes);
	return (0);
}
