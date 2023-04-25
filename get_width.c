#include "main.h"

/**
 * get_width - it Calculates the width for print
 * @format: the Formatted string in which to printing the args.
 * @i: the arguments to be printed in a list.
 * @list: args in a list.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur_i;
	int width = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			width *= 10;
			width += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (width);
}
