#include "sh.h"

/**
 * main - the  main shell execute
 * Return: always 0 (success)
 */
int main(void)
{
	char command[MAX_COMM];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			handle_exit_command();
		}
		else if (strcmp(command, "env") == 0)
		{
			handle_env_command();
		}
		else
		{
			handle_other_command(command);
		}
	}

	return (0);
}
