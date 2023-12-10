/* conversion_operations.c */

#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 *
 * @string: String to be converted.
 *
 * Return: Integer value.
 */
long int _atoi(char *string)
{
int num = 0, count = 0;

if (string == NULL)
return (-1);
if (!string[1])
{
num = string[0] - '0';
return (num);
}
while (string[count] != '\0')
{
if (string[count] >= '0' && string[count] <= '9')
num = (num * 10) + (string[count] - '0');
else
return (-1);
count++;
}
return (num);
}

/**
 * _int_to_string - Converts an integer to a string.
 *
 * @number: Integer to be converted.
 *
 * Return: String representation of the integer.
 */
char *_int_to_string(int number);

