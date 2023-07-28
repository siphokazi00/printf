#include "main.h"

/**
 * print_unsigned - Converts and prints an unsigned int
 * to decimal format.
 * @types: A va_list containing the arguments.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags for formatting the output.
 * @width: Minimum field width for the output.
 * @precision: Precision for the output.
 * @size: The size of the buffer.
 *
 * Return: The number of characters written to the buffer.
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

/**
 * print_octal - Converts and prints an unsigned int to octal format.
 * @types: A va_list containing the arguments.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags for formatting the output.
 * @width: Minimum field width for the output.
 * @precision: Precision for the output.
 * @size: The size of the buffer.
 *
 * Return: The number of characters written to the buffer.
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

/**
 * print_hexadecimal - Converts and prints an unsigned int
 * to hexadecimal format.
 * @types: A va_list containing the arguments.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags for formatting the output.
 * @width: Minimum field width for the output.
 * @precision: Precision for the output.
 * @size: The size of the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Converts and prints an unsigned int
 * to uppercase hexadecimal format.
 * @types: A va_list containing the arguments.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags for formatting the output.
 * @width: Minimum field width for the output.
 * @precision: Precision for the output.
 * @size: The size of the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Converts and prints an unsigned int
 * to hexadecimal format.
 * @types: A va_list containing the arguments.
 * @map_to: The character map used for conversion.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags for formatting the output.
 * @flag_ch: The flag character for the output.
 * @width: Minimum field width for the output.
 * @precision: Precision for the output.
 * @size: The size of the buffer.
 *
 * Return: The number of characters written to the buffer.
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
