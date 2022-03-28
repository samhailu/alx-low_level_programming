#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Double pointer
 * @to: Pointer to char to be assigned to s
 */
void set_string(char **s, char *to)
{
	*s = to;
}
