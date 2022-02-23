/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:12:00 by bexner            #+#    #+#             */
/*   Updated: 2021/05/28 23:36:04 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*iterator;

	if (!lst)
		return (0);
	i = 1;
	iterator = lst;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
		i++;
	}
	return (i);
}
