#include "sh.h"
#include <unistd.h>

/**
 * main - the  main shell execute
 * Return: always 0 (success)
 */
int main(void)
{
	while (1)
	{
		printf("shell$ ");
		char command[MAX_COMM];

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		execute_command(command);
	}
	return (0);
}
