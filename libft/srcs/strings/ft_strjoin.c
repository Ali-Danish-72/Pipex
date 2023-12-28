/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:51:56 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/26 20:44:29 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *string_1, char const *string_2)
{
	size_t	length_string1;
	size_t	length_string2;
	char	*str;

	length_string1 = ft_strlen(string_1);
	length_string2 = ft_strlen(string_2);
	str = (char *)malloc(sizeof(char) * length_string1 + length_string2 + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, string_1, length_string1 + 1);
	*(str + length_string1) = '/';
	ft_strlcpy(str + length_string1 + 1, string_2, length_string2 + 1);
	return (str);
}
