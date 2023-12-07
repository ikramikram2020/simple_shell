/* error_operations.c */

#include "shell.h"

/**
 * _error_handler - Handles and prints error messages during command execution.
 *
 * @name: Name of the shell.
 * @count: Command counter.
 * @command: Array of strings representing the command.
 * @status: Error status (0 for exit, 1 otherwise).
 */
void _error_handler(char *name, int count, char **command, int status);

/**
 * _check_exit - Checks if the command is an exit command.
 *
 * @full_command: Array of strings representing the full command.
 *
 * Return: -1 if invalid number, 0 on success.
 */
int _check_exit(char **full_command);

