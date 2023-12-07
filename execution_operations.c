/* execution_operations.c */

#include "shell.h"

/**
 * _execute_command - Executes a command provided by the user.
 *
 * @argv: Main program arguments.
 * @command: Array of strings as command and its arguments.
 * @count: Number of commands.
 * @env: Environment.
 *
 * Return: 0 on success, 1 on failure.
 */
int _execute_command(char **argv, char **command, int count, char **env);

/**
 * _free_command - Frees memory allocated for a full command array.
 *
 * @full_command: Array of strings representing the command.
 */
void _free_command(char **full_command);

/**
 * _get_input - Gets input from the user.
 *
 * Return: Pointer to a string holding input.
 */
char *_get_input(void);

/**
 * _get_path - Gets the value of the PATH environment variable.
 *
 * Return: Value of the PATH variable.
 */
char *_get_path(void);

/**
 * _print_env - Prints environment values.
 *
 * @env: Environment variables.
 */
void _print_env(char **env);

/**
 * _print_prompt - Prints the shell prompt.
 */
void _print_prompt(void);

/**
 * _check_path - Checks if the command exists in the PATH directories.
 *
 * @command: Command to check.
 *
 * Return: Command path if it exists, otherwise return the command as it was.
 */
char *_check_path(const char *command);

