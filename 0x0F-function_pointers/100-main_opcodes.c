#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of args
 * @argv: Arrays of string args
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i, number_of_bytes;
	unsigned char *code_main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	number_of_bytes = atoi(argv[1]);

	if (number_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	code_main = (unsigned char *)main;

	for (i = 0; i < number_of_bytes - 1; i++)
		printf("%02x ", *code_main++);

	printf("%02x\n", *code_main++);

	return (0);
}
