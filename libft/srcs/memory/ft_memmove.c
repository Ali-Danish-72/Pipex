/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:43:54 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:46:24 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *destination, void const *source, size_t bytes)
{
	void	*dest;

	dest = destination;
	if (destination > source)
	{
		while (bytes--)
			*((char *)destination + bytes) = *((char *)source + bytes);
	}
	else
	{
		while (bytes--)
			*(char *)destination++ = *(char *)source++;
	}
	return (dest);
}
