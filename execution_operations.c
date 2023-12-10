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
 * _get_input - Gets input from the user.
 *
 * Return: Pointer to a string holding input.
 */
char *_get_input(void)
{
char *input = NULL;
size_t n = 0;
ssize_t nbr_chars_read;

nbr_chars_read = getline(&input, &n, stdin);
if (nbr_chars_read == EOF)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "\n", 1);
}
free(input);
exit(0);
}
return (input);
}

/**
 * _get_path - Gets the value of the PATH environment variable.
 *
 * Return: Value of the PATH variable.
 */
char *_get_path(void)
{
int i;

if (environ == NULL)
return (NULL);
for (i = 0; environ[i] != NULL; i++)
{
if ((_strncmp(environ[i], "PATH", 4)) == 0)
return (environ[i] + 5);
}
return (NULL);
}

/**
 * _print_env - Prints environment values.
 *
 * @env: Environment variables.
 */
void _print_env(char **env)
{
int i;
i = 0;
while (env[i] != NULL)
{
write(STDOUT_FILENO, env[i], _strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}

/**
 * _print_prompt - Prints the shell prompt.
 */
void _print_prompt(void)
{
char *prompt = "$ ";

if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, prompt, 2);
}
}

/**
 * _check_path - Checks if the command exists in the PATH directories.
 *
 * @command: Command to check.
 *
 * Return: Command path if it exists, otherwise return the command as it was.
 */
char *_check_path(const char *command)
{
char *path, *new_path, *new_command, *dir, *command_copy;
int dir_len;
int command_len = _strlen(command);
struct stat buf;

command_copy = _strdup(command);
path = _get_path();
if (path)
{
new_path = _strdup(path);
dir = strtok(new_path, ":");
while (dir != NULL)
{
dir_len = _strlen(dir);
new_command = malloc(sizeof(char) * (dir_len + command_len + 2));
_strcpy(new_command, dir);
_strcat(new_command, "/");
_strcat(new_command, command_copy);
_strcat(new_command, "\0");
if (stat(new_command, &buf) == 0)
{
free(new_path);
free(command_copy);
return (new_command);
}
else
{
free(new_command);
dir = strtok(NULL, ":");
}
}
free(new_path);
if (stat(command_copy, &buf) == 0)
return (command_copy);
free(command_copy);
return (NULL);
}
free(command_copy);
return (NULL);
}
