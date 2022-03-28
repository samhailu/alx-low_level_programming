#include "main.h"
#include <stdio.h>

int char_accepted(char *, char);

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: String in wich to search chars
 * @accept: Set of chars that are accepted
 *
 * Return: Pointer to the first char accepted
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		if (char_accepted(accept, *s))
			return (s);
		s++;
	}

	return (NULL);
}

/**
 * char_accepted - Evaluated if a char is in the set of accepted chars
 * @accept: Sset of accepted chars
 * @c: Char to be evaluated
 *
 * Return: 1 if c is in accepted, 0 otherwise
 */
int char_accepted(char *accept, char c)
{
	while (*accept != '\0')
	{
		if (*accept == c)
			return (1);
		accept++;
	}

	return (0);
}
