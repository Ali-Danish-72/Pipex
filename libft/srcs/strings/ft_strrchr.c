/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:38:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:25:18 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(char const *string, int character)
{
	size_t	string_length;

	string_length = ft_strlen(string);
	if ((unsigned char)character == 0)
		return ((char *)(string + string_length));
	while (string_length-- > 0)
		if (*(string + string_length) == (unsigned char)character)
			return ((char *)(string + string_length));
	return (NULL);
}
