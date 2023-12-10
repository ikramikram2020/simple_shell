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
void _error_handler(char *name, int count, char **command, int status)
{
char *string_counter;

string_counter = __itoa(count);
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, string_counter, _strlen(string_counter));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command[0], _strlen(command[0]));
write(STDERR_FILENO, ": ", 2);
if (status == 1)
write(STDERR_FILENO, "not found", 9);
else
{
write(STDERR_FILENO, "Illegal number", 14);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command[1], _strlen(command[1]));
}
write(STDERR_FILENO, "\n", 1);
free(string_counter);
}

/**
 * _check_exit - Checks if the command is an exit command.
 *
 * @full_command: Array of strings representing the full command.
 *
 * Return: -1 if invalid number, 0 on success.
 */
int _check_exit(char **full_command)
{
long int status;

if (_strncmp(full_command[0], "exit", 4) == 0 && !full_command[1])
{
_free_command(full_command);
exit(0);
}
status = _atoi(full_command[1]);
if (_strncmp(full_command[0], "exit", 4) == 0
&& status != -1)
{
_free_command(full_command);
exit(status);
}
else if (_strncmp(full_command[0], "exit", 4) != 0)
return (1);
else
return (-1);
}
