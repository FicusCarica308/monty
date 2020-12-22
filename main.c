#include "monty.h"
/**
 *main - this is our main function for our monty interpretor
 *@av: our agrument list from stream
 *@ac: our argument count from stream
 *Return: returns 0 on succesful completion exits with failure if not
 */
int main(int ac, char **av)
{
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
	get_bytecodes(av[1]);
	return (0);
}
