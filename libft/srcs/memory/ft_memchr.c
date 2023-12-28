/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:11:47 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:34:06 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(void const *string, int character, size_t bytes)
{
	char	*str;

	str = (char *)string;
	while (bytes--)
		if (*str++ == (char)character)
			return ((void *)str - 1);
	return (NULL);
}
