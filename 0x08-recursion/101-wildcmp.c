#include "main.h"
#include <stdio.h>

int wildcmp_rec1(char *, char *, int);
int wildcmp_rec2(char *, char *, int);
char *get_substr(char *);
char *get_end(char *);
char *get_p(char *, char *, char *, char *, char *, char *);

/**
 * wildcmp - Compares if two strings are equals
 * @s1: First string
 * @s2: Second string
 *
 * Return: 1 if s1==s2, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* if '*' means null, s2 just goes to the next position */
	/* if '*' means replacement of any char, s1 goes to next position */
	/* Doing || (or) to both cases, combines all posible ways to find equality */
	/* if any solutions gives 1, then the output will be 1 */
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	return (0);
}

/**
 * wildcmp_old - Compares if two strings are equals
 * @s1: First string
 * @s2: Second string
 *
 * Return: 1 if s1==s2, 0 otherwise
 */
int wildcmp_old(char *s1, char *s2)
{
	return (wildcmp_rec1(s1, s2, 0) || wildcmp_rec2(s1, s2, 0));
}

/**
 * wildcmp_rec1 - Compares if two strings are equals
 * @s1: First string
 * @s2: Special string with special * char
 * @special_char_flag: Int that tells if special char '*' has been passed
 *
 * Return: 1 if s1==s2, 0 otherwise
 */
int wildcmp_rec1(char *s1, char *s2, int special_char_flag)
{
	if (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
			return (wildcmp_rec1(s1 + 1, s2 + 1, 0));

		if (*s2 == '*')
			return (wildcmp_rec1(s1, s2 + 1, 1));

		if (special_char_flag == 1)
			return (wildcmp_rec1(s1 + 1, s2, 1));
	}


	if (*s1 != '\0' && special_char_flag == 1)
		return (1);

	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp_rec1(s1, s2 + 1, 1));

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	return (0);
}

/**
 * wildcmp_rec2 - Compares if two strings are equals
 * @s1: First string
 * @s2: Special string with special * char
 * @special_char_flag: Int that tells if special char '*' has been passed
 *
 * Return: 1 if s1==s2, 0 otherwise
 */
int wildcmp_rec2(char *s1, char *s2, int special_char_flag)
{
	if (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
			return (wildcmp_rec2(s1 + 1, s2 + 1, 0));

		if (*s2 == '*')
		{
			char *pesubs2 = get_substr(s2 + 1);
			char *pes1 = get_end(s1);
			char *pss1 = get_p(pes1, pesubs2, pes1, s1, s2 + 1, pesubs2);

			return (wildcmp_rec2(pss1, s2 + 1, 1));
		}

		if (special_char_flag == 1)
			return (wildcmp_rec2(s1 + 1, s2, 1));
	}

	if (*s1 != '\0' && special_char_flag == 1)
		return (1);

	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp_rec2(s1, s2 + 1, 1));

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	return (0);
}

/**
 * get_substr - Calculates a pointer to the last char of substr of s
 * @s: String from wich to calculate the pointer
 *
 * Return: Pointer to last char of substr
 */
char *get_substr(char *s)
{
	if (*s != '\0' && *s != '*')
		return (get_substr(s + 1));

	return (s - 1);
}

/**
 * get_end - Calculates a pointer to the last char of s
 * @s: String from wich to calculate the pointer
 *
 * Return: Pointer to the last char of s
 */
char *get_end(char *s)
{
	if (*s != '\0')
		return (get_end(s + 1));

	return (s - 1);
}

/**
 * get_p - Calculates the start pointer of s1 that is equal to string
 * between ss2 and es2
 * @s1: Pinter to end of s1
 * @_es2: Pointer to end of substr s2
 * @_ss1: Pointer to start of s1 that coincides with substr s2
 * @ss1: Pointer to start of s1
 * @ss2: Pointer to start of substr s2
 * @es2: Pointer to end of substr s2
 *
 * Return: Pointer to start of substr s1 that coincides with substr s2
 */
char *get_p(char *s1, char *_es2, char *_ss1, char *ss1, char *ss2, char *es2)
{
	if (_es2 < ss2)
		return (_ss1);

	if (s1 < ss1)
		return (ss1);

	if (*s1 == *_es2)
		return (get_p(s1 - 1, _es2 - 1, s1, ss1, ss2, es2));

	return (get_p(s1 - 1, es2, s1 - 1, ss1, ss2, es2));
}
