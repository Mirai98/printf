#include "main.h"

/**
 * is_printable - a f that Evaluates if a char is printable
 * @c: the Char to be evaluated.
 *
 * Return: 1 if c is printable,otherwis e0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - a f that Append ascci in hexadecimal code to buffer
 * @buffer: the Array of chars
 * @i: the Index at which to start appending.
 * @ascii_code: the ASSCI CODE.
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - a f that Verifies if a char is a digit
 * @c: the Char to be evaluated
 *
 * Return: 1 if c is a digit, otherwise 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - a f thatCasts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - a f that Casts a number to the specified size
 * @num: the Number to be casted
 * @size: the Number indicating the type to be casted
 *
 * Return: the Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
