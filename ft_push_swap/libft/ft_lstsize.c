/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:1p2:00 by bexner            #+#    #+#             */
/*   Updated: 2022/01/23 16:29:17 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_listp *lst)
{
	int		i;
	t_listp	*iterator;

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
