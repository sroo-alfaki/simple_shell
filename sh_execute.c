#include "sh.h"
/**
 * execute_command - execute the order
 * @args: input argument
 * Return: null
 */

void execute_command(char **args)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		waitpid(pid, &status, 0);
	}
}
