# Simple Shell Project 🚀

Welcome to the Simple Shell project, one of the most exciting and challenging projects that will test your programming skills and knowledge acquired so far at ALX SE.

## Project Overview 📚

### Basics Covered:
- Programming Fundamentals
- C Programming
- Engineering Thinking
- Group Work
- Learning How to Learn

### Important Reminder ❗
Before diving into the project, make sure to review the [project framework](https://intranet.alxswe.com/concepts/559). Pay close attention to the rules, especially the prohibition against looking at other people's code.

### Project Specifics 📖
The Simple Shell project involves creating a UNIX command-line interpreter. Here are some key points:

- Compile on Ubuntu 20.04 LTS using gcc with specified options.
- Ensure your code follows the Betty style.
- No memory leaks are allowed.
- Group project - work collaboratively with your partner.

## Learning Objectives 🎓
By the end of this project, you should be able to explain:

- Designers of the original Unix OS
- Author of the first Unix shell
- Inventor of the B programming language (predecessor to C)
- Basics of how a shell works
- Concepts such as pid, ppid, environment manipulation, etc.

## Requirements 📝
- Editors: vi, vim, emacs
- Use allowed functions and system calls only
- Follow compilation and testing guidelines
## File Overview 🗂️
## File: string_operations.c

| Function                    | Description                              |
|-----------------------------|------------------------------------------|
| `_strlen(const char *input)`| Returns the length of a string.          |
| `_strdup(const char *input)`| Duplicates a string.                     |
| `_strcpy(char *dest, const char *src)`| Copies a string from source to destination.|
| `_strcmp(const char *first, const char *second, size_t nbr_bytes)`| Compares two strings up to a specified number of bytes.|
| `_strcat(char *dest, const char *src)`| Concatenates two strings.                |


## File: conversion_operations.c

| Function                       | Description                              |
|--------------------------------|------------------------------------------|
| `_atoi(char *string)`           | Converts a string to an integer.         |
| `_int_to_string(int number)`    | Converts an integer to a string.         |


## File: command_operations.c

| Function                          | Description                              |
|-----------------------------------|------------------------------------------|
| `_count_commands(const char *command)`| Counts the number of commands in a string.|
| `_create_command(const char *command)`| Creates a command from a string.         |


## File: error_operations.c

| Function                          | Description                              |
|-----------------------------------|------------------------------------------|
| `_error_handler(char *name, int count, char *command, int status)`| Handles errors and prints relevant information.|
| `_check_exit(char *full_command)`  | Checks if the command is an exit command. |


## File: execution_operations.c

| Function                          | Description                              |
|-----------------------------------|------------------------------------------|
| `_execute_command(char **argv, char *command, int count, char **env)`| Executes a command with arguments.    |
| `_free_command(char *full_command)`| Frees memory allocated for a command.    |
| `_get_input(void)`                | Gets input from the user.               |
| `_get_path(void)`                 | Gets the PATH environment variable.     |
| `_print_env(char *env)`           | Prints the current environment.         |
| `_print_prompt(void)`             | Prints the command prompt.              |
| `_check_path(const char *command)`| Checks if the command is in the PATH.   |

## Tasks Overview 🛠️
### 0. Betty would be proud
Write code that passes the Betty style checks.

### 1. Simple shell 0.1
Implement a basic UNIX command-line interpreter. Handle simple command lines.

### 2. Simple shell 0.2
Extend the shell to handle command lines with arguments.

### 3. Simple shell 0.3
Handle the PATH, and ensure fork is not called if the command doesn’t exist.

### 4. Simple shell 0.4
Implement the exit built-in to exit the shell.

### 5. Simple shell 1.0
Implement the env built-in to print the current environment.

### 6. Simple shell 0.1.1 (Advanced)
Write your own getline function using a buffer.

### 7. Simple shell 0.2.1 (Advanced)
Handle commands without using strtok.

### 8. Simple shell 0.4.1 (Advanced)
Handle arguments for the built-in exit.

### 9. setenv, unsetenv (Advanced)
Implement setenv and unsetenv built-in commands.

### 10. cd (Advanced)
Implement the cd built-in to change the current directory.

### 11. ; (Advanced)
Handle commands separated by semicolons.

### 12. && and || (Advanced)
Handle logical operators && and ||.

### 13. alias (Advanced)
Implement the alias built-in command.

### 14. Variables (Advanced)
Handle variable replacement, including special variables like $? and $$.

### 15. Comments (Advanced)
Handle comments in the shell using #.

### 16. File as input (Advanced)
Enable the shell to take a file as a command line argument and execute commands from the file.

## Usage Examples 🚀
- Interactive mode: `./hsh`
- Non-interactive mode: `echo "/bin/ls" | ./hsh`

## Acknowledgements 🙌
Read or watch materials on Unix shell, Thompson shell, Ken Thompson, and the provided concept pages.


