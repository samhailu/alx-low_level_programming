#include "main.h"
#include <stdio.h>

/**
 * _strchr - Locates a char in a string
 * @s: String in wich to search chars
 * @c: Char to be searched
 *
 * Return: Pointer to the first ocurrence of c
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (c == '\0')
		return (s);

	return (NULL);
}
