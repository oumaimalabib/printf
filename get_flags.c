#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print an arg
 * @i: take the parameter.
 * Return: Flags.
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cur_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cur_i] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = cur_i - 1;

	return (flag);
}
