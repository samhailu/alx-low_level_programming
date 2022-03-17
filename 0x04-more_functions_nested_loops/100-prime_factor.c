#include <stdio.h>
#include <math.h>

int isprime(long);

/**
 * main - Find the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	long n;
	long factor;
	long lpf;

	n = 612852475143;
	factor = 2;

	while (n > 1)
	{
		while (n % factor == 0)
		{
			n /= factor;
			lpf = factor;
		}

		factor++;
	}

	printf("%ld\n", lpf);

	return (0);
}
