/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:29:00 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/28 22:26:06 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*get_next_line(int fd)
{
	char	*store;
	char	*line;

	store = malloc(1000);
	if (!store || fd < 0)
		return (free(store), NULL);
	line = store;
	while (read(fd, store, 1) > 0 && *store != '\n')
		store++;
	if (store == line && *store != '\n')
		return (free(store), NULL);
	*++store = '\0';
	return (line);
}
