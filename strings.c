#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _strlen - finds the length of a string
 * @str: takes a character pointer
 * Return: Always 0
 */

int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

/**
 * _strcpy - Copy a string
 * @dest: Destination value
 * @src: Source string
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	if (dest == src || src == NULL)
	{
		return (dest);
	}
	char i = 0;

	while ((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return (dest);
}

/**
 * duplicate_string - it returns a pointer to a new string
 * which is a copy of the string.
 * @str: string that should be be copied.
 * Return: NULL, if str = NULL
 */

char *duplicate_string(const char *str)
{
	if (str == NULL)
		return (NULL);

	unsigned int length = strlen(str);
        char *duplicate = malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	for (size_t i = 0; i <= length; i++)
	{
		duplicate[i] = str[i]
	}
	return (duplicate);
}

/**
 * _strncat - concatenates 2 strings
 * @dest: takes character pointer
 * @src: takes character pointer
 * @n: takes an integer
 * Return: Always 0
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);  /* Current length of the destination string */

	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];
	}
	dest[dest_length + i] = '\0';  /* Null-terminate the destination string */

	return (dest);
}

/**
 * _strcmp - compares 2 strings
 * @s1: takes character pointer
 * @s2: takes character pointer
 * Return: Always 0
 */

int _strcmp(char *s1, char *s2)
{
	int com;

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		com = 0;
	}
	else if (*s1 < *s2)
	{
		com = -1;
	}
	else
	{
		com = 1;
	}
	return (com);
}
