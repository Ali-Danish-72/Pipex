/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:50:00 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 15:43:11 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	print_number(long int number, int fd)
{
	if (number > -1)
		return (print_unsigned_base(number, fd, DECIMAL, 10));
	write(fd, "-", 1);
	return (1 + print_unsigned_base(number * -1, fd, DECIMAL, 10));
}
