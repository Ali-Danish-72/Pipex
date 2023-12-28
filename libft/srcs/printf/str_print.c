/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:48:50 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 15:43:10 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	print_string(char const *string, int fd)
{
	if (!string)
		return (write(fd, "(null)", 6));
	return (write(fd, string, ft_strlen(string)));
}
