/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_base_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:13:52 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 15:43:07 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	print_unsigned_base(size_t number, int fd, char *base, size_t base_len)
{
	size_t	count;

	count = 0;
	if (number >= base_len)
		count += print_unsigned_base((number / base_len), fd, base, base_len);
	count += print_character(*(base + (number % base_len)), fd);
	return (count);
}
