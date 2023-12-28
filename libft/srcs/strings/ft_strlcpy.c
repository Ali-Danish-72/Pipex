/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:49:27 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:27:35 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcpy(char *destination, char const *source, size_t dest_size)
{
	if (!dest_size)
		return (ft_strlen(source));
	dest_size--;
	while (dest_size-- && *source)
		*destination++ = *source++;
	*destination = '\0';
	return (ft_strlen(source));
}
