/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:01:37 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:26:22 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *string, char (*function)(unsigned int, char))
{
	size_t	index;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (*string)
		*str++ = function(index++, *string++);
	*str = '\0';
	return (str);
}
