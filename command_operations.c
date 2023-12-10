/* command_operations.c */

#include "shell.h"
/**
 * _count_commands - Count commands in a full command string.
 *
 * @command: Full command string to analyze.
 *
 * Return: Number of commands.
 */

int _count_commands(const char *command)
{
char *command_copy;
int command_count = 0;
char *token;
if (command == NULL)
return (0);
command_copy = _strdup(command);
if (command_copy == NULL)
{
return (0);
}
token = strtok(command_copy, " \t\n");
while (token != NULL)
{
command_count++;
token = strtok(NULL, " \t\n");
}
free(command_copy);
return (command_count);
}

