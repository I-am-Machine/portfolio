/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:13:24 by bexner            #+#    #+#             */
/*   Updated: 2021/06/04 11:01:35 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterator;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		iterator = ft_lstlast(*lst);
		iterator->next = new;
	}
	else
		*lst = new;
}
