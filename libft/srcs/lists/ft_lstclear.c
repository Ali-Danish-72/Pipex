/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:20:43 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:53:06 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstclear(t_list **list, void (*delete)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current)
	{
		next = current->next;
		delete(current->content);
		free(current);
		current = next;
	}
	*list = 0;
}
