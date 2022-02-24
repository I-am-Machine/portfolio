/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:13:24 by bexner            #+#    #+#             */
/*   Updated: 2022/02/18 12:27:06 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_listp **lst, t_listp *new)
{
	t_listp	*iterator;

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
