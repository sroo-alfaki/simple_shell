#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMM 100
char *get_input();
char **parse_com(char *command, int *num_args);
void execute_command(char **args);

#endif
