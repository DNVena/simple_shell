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
 * print_env - prints env
 * @envp: takes pointer to pointer
 * Return: integer
 */
int print_env(char **envp)
{
	size_t i = 0;

	while (*envp != NULL)
	{
		while ((*envp)[i] != '\0')
		{
			++i;
		}
		write(STDOUT_FILENO, *envp, i);
		write(STDOUT_FILENO, "\n", 1);
		++envp;
	}
	return (0);
}

void _free(char *buffer, char **path, char **tokens)
{
	free(buffer);
	free(path);
	free(tokens);
}
