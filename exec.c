#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * _fork - forks
 * @args: takes pointer to pointer
 * @envp: takes pointer to pointer
 * Return: integer
 */
int _fork(char **args, char **envp)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("could not fork");
		return (-1);
	}
	if (pid == 0)
	{
		_exec(args, envp);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
/**
 * prep - prepares arguments
 * @buffer: takes pointer
 * @path: takes pointer to pointer
 * Return: pointer to pointer
 */
char **prep(char *buffer, char **path)
{
	char **tokens, *arg, *ex = "exit";

	tokens = tokenize(buffer);
	if (tokens == NULL)
	{
		return (0);
	}
	if (_strcmp(tokens[0], ex) == 0)
	{
		_free(buffer, path, tokens);
		exit(0);
	}
	if ((*tokens)[0] == '/')
	{
		if (access(tokens[0], F_OK) == -1)
		{
			return (NULL);
		}
		else
		{
			return (tokens);
		}
	}
	else
	{
		arg = command(path, tokens[0]);
		if (arg[0] != '/')
		{
			return (NULL);
		}
		else
		{
			tokens[0] = arg;
		}
	}
	return (tokens);
}

/**
 * _exec - executes commands
 * @args: takes pointer to array of arguments
 * @envp: takes pointet to pointer
 * Return: void
 */
void _exec(char **args, char **envp)
{
	if (execve(args[0], args, envp) == -1)
	{
		perror("Error: could not execute");
	}
}
