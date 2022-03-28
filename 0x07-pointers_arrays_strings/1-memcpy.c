#include "main.h"

/**
 * _memcpy - Fills memory with a constant byte
 * @dest: String to wich the values will be copied
 * @src: Source of vals to be copied
 * @n: Number of bytes to be copied
 *
 * Return: Pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int count = 0;

	while (count < n)
	{
		*(dest + count) = *(src + count);
		count++;
	}

	return (dest);
}
