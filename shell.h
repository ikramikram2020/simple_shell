#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/* Print the shell prompt. */
void _print_prompt(void);

/* Execute a command. */
int _execute_command(char *argv[], char *command[], int counter, char *env[]);

/* Calculate the length of a string. */
int _strlen(const char *input);

/* Duplicate a string. */
char *_strdup(const char *input);

/* Copy a string. */
char *_strcpy(char *dest, const char *src);

/* Handle errors during command execution. */
void _error_handler(char *name, int counter, char **command, int status);

/* Count the number of commands in a string. */
int _count_commands(const char *command);

/* Create a full command array from a command string. */
char **_create_command(const char *command);

/* Convert an integer to a string. */
char *_itoa(int number);

/* Get the PATH environment variable. */
char *_get_path(void);

/* Compare two strings up to a specified number of bytes. */
int _strcmp(const char *first, const char *second, size_t no_bytes);

/* Check the PATH for the existence of a command. */
char *_check_path(const char *command);

/* Concatenate two strings. */
char *_strcat(char *dest, const char *src);

/* Get user input. */
char *_get_input(void);

/* Print the environment variables. */
void _print_env(char **env);

/* Check if the command is an exit command. */
int _check_exit(char **full_command);

/* Convert a string to an integer. */
long int _atoi(char *string);

/* Free memory allocated for a full command array. */
void _free_command(char **full_command);

#endif /* _SHELL_H_ */
