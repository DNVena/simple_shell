#include "main.h"
#include <stdlib.h>

/**
 * _strdup - it returns a pointer to a new string
 * which is a copy of the string.
 * @str: string that should be be copied.
 * Return: NULL, if str = NULL
 */

char *_strdup(char *str)
{
	int e = 0, t = 1;
	char *h;

	if (str == NULL)
	return (NULL);

	while (str[t])
	{
		t++;
	}

	h = malloc((sizeof(char) * t) + 1);

	if (h == NULL)
		return (NULL);

	while (e < t)
	{
		h[e] = str[e];
		e++;
	}
	h[e] = '\0';
	return (h);
}
