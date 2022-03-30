#include "main.h"

int get_len(char *c);
int is_palindrome_rec(char *, char *);

/**
 * is_palindrome - Evaluates if a string is palindrome
 * @c: String to be evaluated
 *
 * Return: 1 if string c is palindrome, 0 otherwise
 */
int is_palindrome(char *c)
{
	int len;

	if (*c == '\0')
		return (0);

	len = get_len(c);

	return (is_palindrome_rec(c, c + len - 1));
}

/**
 * get_len - Calculates the length of string c
 * @c: String to calculate the length of
 *
 * Return: Length of c
 */
int get_len(char *c)
{
	if (*c == '\0')
		return (0);

	return (1 + get_len(c + 1));
}

/**
 * is_palindrome_rec - Evaluates if n is prime
 * @left: Pointer to the left of the string
 * @right: Pointer to the right of the string
 *
 * Return: 1 if string is palindrome, 0 otherwise
 */
int is_palindrome_rec(char *left, char *right)
{
	if (*left != *right)
		return (0);

	if (left < right)
		return (is_palindrome_rec(left + 1, right - 1));

	return (1);
}
