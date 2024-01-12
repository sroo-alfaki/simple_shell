#include "sh.h"

/**
 * handle_other_command - input command
 * @command: the order input
 * Return: alway 0
 */
void handle_other_command(char *command)
{
	execute_command(command);
}
