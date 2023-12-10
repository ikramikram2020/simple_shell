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
int _execute_command(char **argv, char **command, int count, char **env)
{
pid_t child;
int status;
char *cmd = _check_path(command[0]);

if (cmd == NULL)
{
_error_handler(argv[0], count, command, 1);
free(cmd);
if (isatty(STDIN_FILENO))
return (127);
exit(127);
}
if (argv == NULL)
{
_free_command(command);
free(cmd);
return (1);
}
child = fork();
if (child < 0)
{
perror("fork");
_free_command(command);
free(cmd);
exit(1);
}
else if (child == 0)
execve(cmd, command, env);
else
{
free(cmd);
waitpid(child, &status, 0);
}
return (0);
}

/**
 * _free_command - Frees memory allocated for a full command array.
 *
 * @full_command: Array of strings representing the command.
 */
void _free_command(char **full_command)
{
int i;

i = 0;
while (full_command[i] != NULL)
{
free(full_command[i]);
i++;
}
free(full_command);
}

/**
 * _create_command - creates an array of strings from a command
 *
 * @command: command to create an array of strings from
 *
 * Return: array of strings of the full command
 */
char **_create_command(const char *command)
{
int nbr_command, i;
const char *delim = " \t\n";
char *command_copy, *single_command;
char **full_command;

if (command == NULL)
return (0);
nbr_command = _count_commands(command);
if (nbr_command == 0)
return (NULL);
command_copy = _strdup(command);
full_command = malloc(sizeof(char *) * (nbr_command + 1));
if (full_command == NULL)
{
perror("malloc");
_free_command(full_command);
free(command_copy);
exit(1);
}
single_command = strtok(command_copy, delim);
for (i = 0; single_command != NULL; i++)
{
full_command[i] = malloc(sizeof(char) * _strlen(single_command) + 1);
if (full_command[i] == NULL)
{
perror("malloc");
_free_command(full_command);
free(command_copy);
free(single_command);
exit(1);
}
_strcpy(full_command[i], single_command);
single_command = strtok(NULL, delim);
}
full_command[i] = NULL;
free(command_copy);
command_copy = NULL;
free(single_command);
return (full_command);
}
