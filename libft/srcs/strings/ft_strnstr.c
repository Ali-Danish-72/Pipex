/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:56:24 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:25:41 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	needle_match(char const *haystack, char const *needle, size_t length)
{
	while (length && *haystack++ == *needle++)
		length--;
	if (!length)
		return (1);
	return (0);
}

char	*ft_strnstr(char const *haystack, char const *needle, size_t length)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (needle_match(haystack, needle, length))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
