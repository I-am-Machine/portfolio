/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:11:57 by bexner            #+#    #+#             */
/*   Updated: 2022/02/18 12:26:09 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**NAME
**	ft_lstiter
**SYNOPSIS
**	#include "libft.h"
**	void ft_lstiter(t_list *lst, void (*f)(void*));
**PARAMETERS
**	t_list *lst		->The adress of a pointer to first element.
**	void (*f)(void*)	->The adress of the function to use on all Contents
**DESCRIPTION
**	Iterates the list and applies function to each content of each element.
*/

#include "libft.h"

void	ft_lstiter(t_listp *lst, void (*f)(void*))
{
	t_listp	*iterator;

	if (!lst || !f)
		return ;
	iterator = lst;
	while (iterator)
	{
		(*f)(iterator->content);
		iterator = iterator->next;
	}
}
