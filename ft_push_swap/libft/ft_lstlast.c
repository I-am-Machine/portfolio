/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:33:57 by bexner            #+#    #+#             */
/*   Updated: 2022/02/18 12:26:23 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listp	*ft_lstlast(t_listp *lst)
{
	int		i;
	t_listp	*iterator;

	if (!lst)
		return (NULL);
	i = 1;
	iterator = lst;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
		i++;
	}
	return (iterator);
}
