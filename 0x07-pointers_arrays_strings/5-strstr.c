#include "main.h"
#include <stdio.h>

int substr_exists(char *, char *);

/**
 * _strstr - Locates a substring
 * @haystack: String of chars
 * @needle: Substring to be found
 *
 * Return: Pointer to the beginning of the substring
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		if (substr_exists(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (NULL);
}

/**
 * substr_exists - Evaluates if substring exists on string
 * @s: String of chars
 * @sub: String to be searched in s
 *
 * Return: 1 if sub is found, 0 otherwise
 */
int substr_exists(char *s, char *sub)
{
	while (*s != '\0' && *sub != '\0')
	{
		if (*s != *sub)
			return (0);
		s++;
		sub++;
	}

	return (1);
}
