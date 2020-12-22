#include "lists.h"
/**
 * 
 */
void free_file(FILE *fd, char *line, char **op_codes)
{
		free(line);
		fclose(fd);
		errors("malloc", 0, NULL, op_codes);
}
/**
*len_av - finds the length our argument list will be
*@name: the name of the file to be opened
*Return: returns the length of the arugment list
*/
int len_av(char *name)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int read_chars;
	int count = 0;

	fp = fopen(name, "r");

	while ((read_chars = getline(&line, &len, fp)) != -1)
		count++;
	free(line);
	fclose(fp);
	return (count);
}
/**
*get_bytecodes - Retrieves bytecodes from a given file
*@name: a string contaning our file name or directory path
*Return: returns a full list of bytecodes in order
*/
char **get_bytecodes(char *name)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int read_chars;
	char **op_codes = NULL;
	int count = len_av(name);
	int i = 0;

	

	op_codes = malloc(sizeof(char *) * (count + 1));
	if (op_codes == NULL)
		errors("malloc", 0, NULL, op_codes);

	fp = fopen(name, "r");

	while ((read_chars = getline(&line, &len, fp)) != -1)
	{
		op_codes[i] = malloc((strlen(line) + 1) * sizeof(char));
		if (op_codes[i] == NULL)
			free_file(fp, line, op_codes);
		strcpy(op_codes[i], line);
		i++;
	}
	op_codes[i] = NULL;
	free(line);
	fclose(fp);
	return (op_codes);
}
