#include "sh.h"
#define MAX_COMM 100
/**
 * **parse_com - creat spilt of command to argument
 * @command: the order input
 * @num_args: number of argument
 * Return: argument
 */
char **parse_com(char *command, int *num_args)
{
	static char *args[MAX_COMM];
	char *tok = strtok(command, " ");
	
	*num_args = 0;
	while (tok != NULL && *num_args < MAX_COMM - 1)
	{
		args[*num_args] = tok;
		(*num_args)++;
		tok = strtok(NULL, " ");
	}
	args[*num_args] = NULL;
	return (args);
}
