#include "main.h"

/**
 * get_width - Extracts width specifier from the format string.
 * @format: Pointer to the format string.
 * @i: Pointer to the current position in the format string.
 * @list: va_list of arguments to the function.
 *
 * Return: The width specifier extracted from the format string,
 * or 0 if not specified.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
