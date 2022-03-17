#include "main.h"

int reverse_punit(int);
void print_rev(int);
void handle_n_less(int);
void handle_n_great(int, int);

/**
 * print_number - Prints an integer char by char
 * @n: number to be printed
 */
void print_number(int n)
{
	int divisor;

	divisor = 10000;

	if (n < 0)
		if (n > -divisor)
			handle_n_less(n);
		else
			handle_n_great(n, divisor);
	else
		if (n < divisor)
			handle_n_less(n);
		else
			handle_n_great(n, divisor);
}

/**
 * handle_n_less - Handle cases when n < divisor
 * @n: number to be printed
 */
void handle_n_less(int n)
{
	int rev;
	int n_is_negative;

	n_is_negative = 0;

	if (n < 0)
	{
		n *= -1;
		n_is_negative = 1;
	}

	rev = reverse_punit(n);

	if (n_is_negative)
		_putchar('-');

	print_rev(rev);
}

/**
 * handle_n_great - Handles cases when n > divisor
 * @n: number to be printed
 * @divisor: Number to handle digits for each half
 */
void handle_n_great(int n, int divisor)
{
	int rev1, rev2;
	int half1, half2;

	half1 = n / divisor;
	half2 = n % divisor;

	if (n < 0)
	{
		half1 *= -1;
		half2 *= -1;
	}

	/* Add divisor to half2 to avoid loosing middle 0's in n */
	half2 += divisor;

	rev1 = reverse_punit(half1);
	rev2 = reverse_punit(half2);

	/* Delete extra unit given by divisor */
	rev2 /= 10;

	if (n < 0)
		_putchar('-');

	print_rev(rev1);
	print_rev(rev2);
}

/**
 * reverse_punit - Reverses a number with an extra unit at left
 * @n: number to reversed
 *
 * Return: n reversed plus 1 unit at the beggining
 */
int reverse_punit(int n)
{
	int rev;

	rev = 1;
	do {
		rev *= 10;
		rev += n % 10;
		n = n / 10;
	} while (n > 0);

	return (rev);
}

/**
 * print_rev - Prints a number in reverse order
 * @n: number to be printed
 */
void print_rev(int n)
{
	do {
		_putchar('0' + (n % 10));
		n /= 10;
	} while (n >= 10);
}
