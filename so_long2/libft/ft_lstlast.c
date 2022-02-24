/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:33:57 by bexner            #+#    #+#             */
/*   Updated: 2021/05/29 11:21:36 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*iterator;

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
