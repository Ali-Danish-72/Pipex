/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:56:10 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/21 10:13:20 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	format(char *specifier, va_list ap, int fd)
{
	size_t	length;

	if (*specifier == 'c')
		length = print_character(va_arg(ap, int), fd);
	else if (*specifier == 's')
		length = print_string(va_arg(ap, const char *), fd);
	else if (*specifier == 'p')
		length = print_address(va_arg(ap, void *), fd);
	else if (*specifier == 'd' || *specifier == 'i')
		length = print_number(va_arg(ap, int), fd);
	else if (*specifier == 'l')
		length = print_number(va_arg(ap, long int), fd);
	else if (*specifier == 'u')
		length = print_unsigned_base(va_arg(ap, size_t), fd, DECIMAL, 10);
	else if (*specifier == 'x' || *specifier == 'X')
		length = print_hexadecimal(va_arg(ap, size_t), *specifier, fd);
	else
		length = write(fd, specifier, 1);
	return (length);
}

size_t	ft_printf(int fd, char *string, ...)
{
	size_t	string_length;
	va_list	ap;

	if (!string || fd < 0)
		return (0);
	string_length = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
			string_length += format(++string, ap, fd);
		else
			string_length += print_character(*string, fd);
		if (*string)
			string++;
	}
	va_end(ap);
	return (string_length);
}
