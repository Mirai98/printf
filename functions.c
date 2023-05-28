#include "main.h"

/**
 * print_char - a f that prints a char
 * @types: The list a of arguments
 * @buffer: The buffer array to handle print
 * @flags:  To calculates active flags
 * @width: The width
 * @precision: The precision specification
 * @size: the size specifier
 * Return: The number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char C = va_arg(types, int);

	return (handle_write_char(C, buffer, flags, width, precision, size));
}


/**
 * print_string - A f that prints a string
 * @types: The list a of arguments
 * @buffer: the buffer array to handle print
 * @flags:  To calculates active flags
 * @width: width.
 * @precision: the precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int Length = 0;
	int a;
	char *st_r = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (st_r == NULL)
	{
		st_r = "(null)";
		if (precision >= 6)
			st_r = "      ";
	}

	while (st_r[Length] != '\0')
		Length++;

	if (precision >= 0 && precision < Length)
		Length = precision;

	if (width > Length)
	{
		if (flags & F_MINUS)
		{
			write(1, &st_r[0], Length);
			for (a = width - Length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - Length; a > 0; a--)
				write(1, " ", 1);
			write(1, &st_r[0], Length);
			return (width);
		}
	}
	return (write(1, st_r, Length));
}


/**
 * print_percent - A f that prints a percent sign
 * @types: the lista of arguments
 * @buffer: the buffer array to handle print
 * @flags:  to calculates active flags
 * @width: width.
 * @precision: The precision specification
 * @size: the size specifier
 * Return: the number of chars printed
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



/**
 * print_int - a f that Print int
 * @types: The list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  To calculates active flags
 * @width: width.
 * @precision: The Precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_negative, a, buffer, flags, width, precision, size));
}



/**
 * print_binary - a f that Prints an unsigned number
 * @types: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  to calculates active flags
 * @width: width.
 * @precision: the Precision specification
 * @size: the size specifier
 * Return: the numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, M, I, Sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	M = 2147483648;
	a[0] = n / M;
	for (I = 1; I < 32; I++)
	{
		M /= 2;
		a[I] = (n / M) % 2;
	}
	for (I = 0, Sum = 0, count = 0; I < 32; I++)
	{
		Sum += a[I];
		if (Sum || I == 31)
		{
			char z = '0' + a[I];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
