/* string_operations.c */

#include "shell.h"

/**
 * _strlen - Get the length of a string.
 *
 * @input_string: The string to measure.
 *
 * Return: The length of the string.
 */
int _strlen(const char *input_string)
{
    int length;

    /* Count each character until the end of the string is reached. */
    for (length = 0; input_string[length] != '\0'; length++)
        ;

    return (length);
}

/**
 * _strdup - Duplicate a string.
 *
 * @original_string: The string to duplicate.
 *
 * Return: A new string identical to the original.
 */
char *_strdup(const char *original_string)
{
    char *duplicate;
    int index;

    /* Allocate memory for the new string. */
    duplicate = malloc(sizeof(char) * (_strlen(original_string) + 1));

    /* Check if memory allocation was successful. */
    if (duplicate == NULL)
    {
        perror("malloc");
        exit(1);
    }

    /* Copy each character from the original string to the new string. */
    for (index = 0; original_string[index] != '\0'; index++)
        duplicate[index] = original_string[index];

    duplicate[index] = '\0';
    return (duplicate);
}

/**
 * _strcpy - Copy a string.
 *
 * @destination: The buffer to copy into.
 * @source: The string to copy.
 *
 * Return: The destination buffer with the copied string.
 */
char *_strcpy(char *destination, const char *source)
{
    int index;

    /* Copy each character from the source string to the destination buffer. */
    for (index = 0; source[index] != '\0'; index++)
        destination[index] = source[index];

    destination[index] = '\0';
    return (destination);
}

/**
 * _strncmp - Compare two strings up to a certain number of characters.
 *
 * @first_string: The first string to compare.
 * @second_string: The second string to compare.
 * @num_bytes: The number of characters to compare.
 *
 * Return: 0 if the strings are equal, a positive value if the first string is
 * greater, and a negative value if the second string is greater.
 */
int _strncmp(const char *first_string, const char *second_string,
		size_t num_bytes)
{
    size_t index;

    /* Compare each character up to the specified number of bytes. */
    for (index = 0; index < num_bytes; index++)
    {
        if (first_string[index] == second_string[index])
            continue;
        return (1);
    }

    return (0);
}

/**
 * _strcat - Concatenate two strings.
 *
 * @destination: The buffer to concatenate into.
 * @source: The string to append.
 *
 * Return: The destination buffer with the concatenated string.
 */
char *_strcat(char *destination, const char *source)
{
    int dest_index, source_index;

    /* Find the end of the destination string. */
    for (dest_index = 0; destination[dest_index] != '\0'; dest_index++)
        ;

    /* Append each character from the source string to the destination string. */
    for (source_index = 0; source[source_index] != '\0'; source_index++)
        destination[source_index + dest_index] = source[source_index];

    destination[source_index + dest_index] = '\0';
    return (destination);
}
