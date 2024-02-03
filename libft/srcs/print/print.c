/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:56:10 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/21 10:13:20 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print(char *string1, char *string2)
{
	write(2, string1, ft_strlen(string1));
	write(2, string2, ft_strlen(string2));
}
