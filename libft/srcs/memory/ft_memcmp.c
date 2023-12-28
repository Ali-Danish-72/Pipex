/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:03:21 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:46:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_memcmp(void const *string1, void const *string2, size_t bytes)
{
	char	*str1;
	char	*str2;

	str1 = (char *)string1;
	str2 = (char *)string2;
	while (bytes && *str1++ == *str2++)
		bytes--;
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
