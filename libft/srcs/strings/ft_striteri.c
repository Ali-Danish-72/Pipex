/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:25:05 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:28:35 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_striteri(char const *string, void (*function)(unsigned int, char *))
{
	size_t	string_length;

	string_length = ft_strlen(string);
	while (string_length--)
		function(string_length, (char *)(string + string_length));
}
