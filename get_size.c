#include "main.h"

/**
 * get_size - The function calculate  size
 * @format: This is the format strng where to print the args
 * @i: List of args
 * Return: returns the preccision.
 */
int get_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int size = 0;

	if (format[cur_i] == 'l')
		size = S_LONG;
	else if (format[cur_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur_i - 1;
	else
		*i = cur_i;

	return (size);
}

