#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints sum of both diagonals individually
 * @a: Pointer to the first element of matrix
 * @size: Size of matrix sizeXsize
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	int main_diag_sum, sec_diag_sum;

	main_diag_sum = 0;
	sec_diag_sum = 0;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (i == j)
			{
				main_diag_sum += a[(i * size) + j];
				sec_diag_sum += a[(i * size) + (size - 1 - j)];
			}

	printf("%d, %d\n", main_diag_sum, sec_diag_sum);
}
