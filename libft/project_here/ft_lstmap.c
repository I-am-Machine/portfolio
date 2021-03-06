/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:25:28 by bexner            #+#    #+#             */
/*   Updated: 2021/06/11 11:28:26 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	if (!lst)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (!node)
		return (NULL);
	head = node;
	while (lst)
	{
		if (lst->next)
		{
			node->next = ft_lstnew(f(lst->next->content));
			if (!(node->next))
			{
				ft_lstclear(&node, del);
				return (NULL);
			}
			node = node->next;
		}
		lst = lst->next;
	}
	node->next = NULL;
	return (head);
}
