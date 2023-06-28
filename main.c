#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - runs simple shell
 * Return: Always (0)
 */
int main(void)
{
	char **args, **envp, **path, *buffer = NULL, *prompt = "$ ";
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
		else
		{
			path = sep_path(envp);
			args = prep(buffer, path);
			if (args == NULL)
			{
				perror("Did not find command");
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
