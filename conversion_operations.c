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
char *_int_to_string(int number)
{
int nbr_digits = 0, temp;
char *string_int;

temp = number;
if (number == 0)
nbr_digits = 1;
else
{
while (number != 0)
{
number /= 10;
nbr_digits++;
}
}
string_int = malloc(sizeof(char) * (nbr_digits + 1));
if (string_int == NULL)
{
perror("malloc");
return (NULL);
}
string_int[nbr_digits] = '\0';
while (nbr_digits > 0)
{
string_int[nbr_digits - 1] = '0' + (temp % 10);
temp /= 10;
nbr_digits--;
}
return (string_int);
}
