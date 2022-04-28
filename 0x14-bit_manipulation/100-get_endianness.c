#include "main.h"

/**
 * get_endianness - Gets the Endianness of the machine
 *
 * Return: 0 if Big Endian, 1 if Little Endian
 */
int get_endianness(void)
{
	/* Big endian: */
	/* stores the most significant byte at the smallest memory address */
	/* Little endian: */
	/* stores the least-significant byte at the smallest address */
	unsigned int n = 1;
	char *c = (char *)&n;

	/* If the byte at the smallest memory addrs is 1, then is Less endian */
	if (*c)
		return (1);

	return (0);
}
