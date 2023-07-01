#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _strncmp - compares 2 strings
 * @s1: takes pointer
 * @s2: takes pointer
 * @n: takes integer
 * Return: integer
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _free - frees memory
 * @buffer: takes pointer
 * @path: takes pointer
 * @tokens: takes pointer
 * Return: void
 */
void _free(char *buffer, char **path, char **tokens)
{
	free(buffer);
	free(path);
	free(tokens);
}

/**
 * _isspace - checks for empty string
 * @str: takes pointer
 * Return: integer
 */
int _isspace(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r')
		{
			return (1);
		}
		str++;
	}
	return (0);
}
