/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:38:05 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/25 10:27:20 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putunbr_base_fd(long int number, int fd, char *base, int base_len)
{
	if (fd >= 0)
	{
		if (number >= base_len)
			ft_putunbr_base_fd((number / base_len), fd, base, base_len);
		ft_putchar_fd(*(base + (number % base_len)), fd);
	}
}
