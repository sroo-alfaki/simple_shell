#include "sh.h"

/**
 * handle_env_command - input command
 * Return: alway 0
 */
void handle_env_command(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
