/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:55:49 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:30:36 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *string, int fd)
{
	if (fd >= 0)
	{
		ft_putstr_fd(string, fd);
		ft_putchar_fd('\n', fd);
	}
}
