/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:12:24 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:53:40 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_back(t_list **list, t_list *new_node)
{
	t_list	*last;

	if (!*list)
		*list = new_node;
	else
	{
		last = ft_lstlast(*list);
		last->next = new_node;
	}
}
