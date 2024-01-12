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

	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execlp(command, command, NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
