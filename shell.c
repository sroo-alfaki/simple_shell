#include "sh.h"
#include <unistd.h>

/**
 * main - the  main shell execute
 * Return: always 0 (success)
 */
int main(void)
{
	int i;

	while (1)
	{
		char *command = get_input();

		if (command == NULL)
		{
			printf("\n");
			break;
		}
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "env") == 0)
		{
			extern char **environ;

			for (i = 0; environ[i] != NULL; i++)
			{
				printf("%s\n", environ[i]);
			}
		}
		else
		{
			int num_args;
			char **args = parse_com(command, &num_args);

			if (num_args > 0)
			{
				execute_command(args);
			}
		}
	}

	return (0);
}
