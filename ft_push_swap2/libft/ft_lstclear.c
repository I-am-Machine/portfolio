/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:11:51 by bexner            #+#    #+#             */
/*   Updated: 2022/02/18 12:26:42 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**NAME
* ft_clear
**Synopsis
* #include "libft.h"
**Prototype
* void ft_lstclear(t_list **lst, void (*del)(void*))
**Arguments
* Adress to pointer of first Element
* Adress to function used to Delete the Content of Element
** External Functions:
* free();
** Description
* it deletes and frees the given Element and every succesor of that Element,
* using the function 'del'
* and free
*/

#include "libft.h"

void	ft_lstclear(t_listp **lst, void (*del)(void *))
{
	t_listp	*iterator;

	if (!del || !*lst || !lst)
		return ;
	while (lst && *lst)
	{
		iterator = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = iterator;
	}
}
