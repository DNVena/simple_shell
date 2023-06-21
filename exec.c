#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _exec - execute commands
 * @args: takes pointer to array of arguments
 * Return: void
 */

void _exec(char **args)
{
	extern char **environ;

	if  (execve(args[0], args, environ) == -1)
	{
		perror("Error: command not found");
	}
}
