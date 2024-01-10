#include "sh.h"
/**
 * execute_command - execute the order
 * @command: input argument
 * Return: null
 */
void execute_command(char *command)
{
	if (strcmp(command, "cd") == 0)
	{
		chdir("/path/to/desired/directory");
		return;
	}
	else if (strcmp(command, "echo") == 0)
	{
		printf("Hello, World!\n");
		return;
	}
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Forking error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = {command, NULL};

		execvp(args[0], args);
		perror("Command execution error");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				printf("Command exited with status %d\n", exit_status);
			}
		}
	}
}
