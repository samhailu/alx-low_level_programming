#include "main.h"

int is_prime(int, int);

/**
 * is_prime_number - Evaluates if a number is prime
 * @n: Number to be evaluated
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_prime(n, 2));
}

/**
 * is_prime - Evaluates if n is prime
 * @n: Num to be evaluated
 * @divisor: N
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime(int n, int divisor)
{
	if (divisor == n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_prime(n, divisor + 1));
}
