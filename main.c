#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - runs simple shell
 * @argc: unused
 * @argv: takes pointer to pointer
 * Return: Always (0)
 */
int main(int __attribute__ ((unused)) argc, char **argv)
{
	char **args, **envp, **path, *buffer = NULL, *envy = "env", *prompt = "$ ";
	ssize_t result;
	size_t len = 0;

	envp = environ;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			_putchar(prompt[0]);
			_putchar(prompt[1]);
		}
		result = getline(&buffer, &len, stdin);
		if (result == -1)
		{
			break;
		}
		if (_strcmp(buffer, envy) == 0)
		{
			print_env(envp);
			return (0);
		}
		else
		{
			path = sep_path(envp);
			args = prep(buffer, path);
			if (args == NULL)
			{
				puts_error(argv[0], buffer);
			}
			else
			{
				_fork(args, envp);
			}
			free(path);
			free(args);
		}
	}
	free(buffer);
	return (0);
}
