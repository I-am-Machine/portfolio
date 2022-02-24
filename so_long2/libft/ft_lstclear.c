/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:11:51 by bexner            #+#    #+#             */
/*   Updated: 2021/06/04 11:03:42 by bexner           ###   ########.fr       */
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iterator;

	if (!del || !*lst || !lst)
		return ;
	while (lst && *lst)
	{
		iterator = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = iterator;
	}
}
