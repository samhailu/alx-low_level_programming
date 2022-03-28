#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: Pointer to be filled
 * @b: Byte used to fill the memory
 * @n: Number of bytes to be filled
 *
 * Return: Pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count = 0;

	while (count < n)
	{
		*(s + count) = b;
		count++;
	}

	return (s);
}
