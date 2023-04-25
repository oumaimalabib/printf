#include "main.h"

/**
 * get_precision - This fubction gets the precision
 * @format: Represent the Format string to which we print the args
 * @i: This is the list of args
 * @list: is the list of args
 * Return: returns the precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur_i = *i + 1;
	int precisions = -1;

	if (format[cur_i] != '.')
		return (precisions);

	precisions = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			precisions *= 10;
			precisions += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precisions = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (precisions);
}
