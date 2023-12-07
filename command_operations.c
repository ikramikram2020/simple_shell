/* command_operations.c */

#include "shell.h"

/**
 * _count_commands - Counts the number of commands in a string.
 *
 * @command: Full command string.
 *
 * Return: Number of commands.
 */
int _count_commands(const char *command);

/**
 * _create_command - Creates an array of strings from a command.
 *
 * @command: Command string.
 *
 * Return: Array of strings representing the full command.
 */
char **_create_command(const char *command);

