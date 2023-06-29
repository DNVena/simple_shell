#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints char
 * @c: takes char
 * Return: void
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * puts_err - prints in stderr
 * @c: takes char
 * Return: void
 */
void puts_err(char c)
{
	write(2, &c, 1);
}

/**
 * puts_error - prints error
 * @hsh: takes pointer
 * @arg: takes pointer
 * Return: void
 */
void puts_error(char *hsh, char *arg)
{
	int i, j, k;
	int len1, len2, len3;
	char *err = "not found";

	len1 = _strlen(hsh);
	len2 = _strlen(arg);
	len3 = _strlen(err);

	for (i = 0; i < len1; i++)
	{
		puts_err(hsh[i]);
	}
	puts_err(':');
	puts_err(' ');
	puts_err('1');
	puts_err(':');
	puts_err(' ');
	for (j = 0; j < len2; j++)
	{
		puts_err(arg[j]);
	}
	puts_err(':');
	puts_err(' ');
	for (k = 0; k < len3; k++)
	{
		puts_err(err[k]);
	}
	puts_err('\n');
}
