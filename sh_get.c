#include "sh.h"

/**
 * get_input- input command
 * Return: result function
 */

char *get_input()
{
	static char command[MAX_COMM];
	char *result = NULL;

	if (fgets(command, sizeof(command), stdin))
	{
		result = command;
		command[strcspn(command, "\n")] = ('\0');
	}

	return (result);
}
