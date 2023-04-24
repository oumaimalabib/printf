#include "main.h"

/* discriprtion of PRINT UNSIGNED NUM */
/**
 * print_unsigned - this Prints unsigned number
 * @types: the list of arg
 * @buffer: Handle print for buffer array
 * @flags:  its Calculates that  active flags
 * @width: to width
 * @precision: specification precision
 * @size: Specifier size
 * Return: chars printe in num.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* discription that PRINT UNSIGNED NUMB IN OCTAL */
/**
 * print_octal - Prints the unsigned num in octal notation
 * @types: arguments in list
 * @buffer: handle print to buffer array
 * @flags: it Calculates the active flags
 * @width: to width
 * @precision: Specification precision
 * @size: Specifier SIZE
 * Return: chars printed in num
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* discription that PRINT UNSIGNED NUM IN HEXADECIMAL */
/**
 * print_hexadecimal - this Print an unsigned number in hexadecimal notation
 * @types: arguments in list
 * @buffer: handle print buffer array
 * @flags: it Calculates the  active flags
 * @width: to width
 * @precision: specification for precision
 * @size: Specifier the size
 * Return: the Num of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* discription for PRINT UNSIGNED NUM IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - this Print unsigned number in upper hexadecimal notation
 * @types: the list of arguments
 * @buffer: handle print in buffer array
 * @flags:  its Calculates the active flags
 * @width: to width
 * @precision: specification precision
 * @size: Specifier size
 * Return: the Num of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* discription for  PRINT HEXX NUM IN LOWER OR UPPER */
/**
 * print_hexa - this Prints a hexadecimal num in lower or upper
 * @types: a list of arguments
 * @map_to: Array of values that map the num to
 * @buffer: Buffer array to handle print
 * @flags:  it Calculates the active flags
 * @flag_ch: it Calculates the active flags
 * @width: to width
 * @precision: specification of precision
 * @size: Specifier the size
 * @size: Specification the size
 * Return: Number of charcters printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
