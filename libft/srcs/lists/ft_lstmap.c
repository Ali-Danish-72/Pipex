/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:33:10 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/23 20:42:30 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *list, void *(*function)(void*), void (*del)(void*))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!list || !function)
		return (NULL);
	new_list = NULL;
	while (list)
	{
		content = function(list->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		list = list->next;
	}
	return (new_list);
}
