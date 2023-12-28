/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:48:06 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:27:55 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *destination, char const *source, size_t dest_size)
{
	size_t	dst_len;
	size_t	total;

	dst_len = 0;
	while (*(destination + dst_len) && dst_len < dest_size)
		dst_len++;
	if (dst_len == dest_size)
		return (dest_size + ft_strlen(source));
	else
		total = dst_len + ft_strlen(source);
	while ((dst_len + 1 < dest_size) && *source)
		*(destination + dst_len++) = *source++;
	*(destination + dst_len) = '\0';
	return (total);
}
