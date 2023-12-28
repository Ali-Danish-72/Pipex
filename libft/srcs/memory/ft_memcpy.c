/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:02:20 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:46:31 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *destination, void const *source, size_t bytes)
{
	void	*dest;

	dest = destination;
	while (bytes--)
		*(char *)destination++ = *(char *)source++;
	return (dest);
}
