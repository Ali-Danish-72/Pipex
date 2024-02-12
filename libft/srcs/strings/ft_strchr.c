/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:41 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:19:54 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(char const *string, int character)
{
	if (!character)
		return ((char *)(string + ft_strlen(string)));
	while (*string)
	{
		if (*string == (unsigned char)character)
			return ((char *)string);
		string++;
	}
	return (NULL);
}
