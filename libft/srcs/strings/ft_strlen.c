/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:10:18 by mdanish           #+#    #+#             */
/*   Updated: 2024/02/03 21:02:27 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(char const *string)
{
	size_t	string_length;

	if (!string)
		return (0);
	string_length = 0;
	while (*string++)
		string_length++;
	return (string_length);
}
