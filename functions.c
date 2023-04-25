#include "main.h"

/* decirption of  PRINT CHARACTER */
/**
 * print_char - Thjis function prints a character
 * @types: Determines the  list a of arguments
 * @buffer: This  Buffer is array that handles the print
 * @flags:  this calculates flags that are active
 * @width: determines the Width
 * @precision: This is the Precision spec
 * @size: This is the Size spec
 * Return: the number of chars to be printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/* description of  PRINT STRING */
/**
 * print_string - this fuction Prints a string
 * @types: This is a  List of arguments
 * @buffer: Buffer the wanted array to handle the print
 * @flags:  Calculates the flags that are active
 * @width: gets the width
 * @precision: This is  Precision spec
 * @size: Size of the specifier
 * Return: The number of characters printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/* description of the PRINT PERCENT_sign*/
/**
 * print_percent - Funct Prints the percent sign
 * @types: Listing of args
 * @buffer: Buffer array that will handle the  print
 * @flags:  Calculates the flags that are active
 * @width: gets the width
 * @precision: DEtermunes the  Precision spec
 * @size: This is  Size spec
 * Return: returns the number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*definition of PRINT INT */
/**
 * print_int - the function Print int
 * @types: This is a list of args
 * @buffer: Buffer the array to handle print
 * @flags:  Calculates the flags that are active
 * @width: gets the width
 * @precision: determines the Precision spec
 * @size: this is the size specifie
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negativ = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negativ = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negativ, i, buffer, flags, width, precision, size));
}

/* defining the fuction PRINT BINARY */
/**
 * print_binary -This function Prints an unsigned number
 * @types: this is a list of args
 * @buffer: This is the Buffer array that handles the print
 * @flags:  This  calculates the flags that are activated
 * @width: gets the width
 * @precision: determines the Precision spec
 * @size: Size specifier
 * Return: results of numbers of characters printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int countt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, countt = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			countt++;
		}
	}
	return (countt);
}
