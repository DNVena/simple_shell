#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * len_buf - finds the number of tokens
 * @buffer: takes pointer to arguments
 * Return: (integer) number of tokens
 */
int len_buf(char *buffer)
{
	char *lines;
	int num = 0;

	lines = strtok(buffer, " ");
	while (lines != NULL)
	{
		num++;
		lines = strtok(NULL, " ");
	}
	num++;
	return (num);
}

/**
 * tokenize - tokenises arguments
 * @buffer: takes pointer to arguments
 * Return: pointer to array of tokens
 */
char **tokenize(char *buffer)
{
	int i = 0, num;
	char *token;
	char **args;
	char *buf_cpy = (char *)malloc(1024);

	if (!buf_cpy)
		return (NULL);
	_strcpy(buf_cpy, buffer);
	num = len_buf(buf_cpy);
	args = malloc(sizeof(char *) * (num + 1));

	if (!args)
		return (NULL);
	token = strtok(buffer, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	free(buf_cpy);
	return (args);
}