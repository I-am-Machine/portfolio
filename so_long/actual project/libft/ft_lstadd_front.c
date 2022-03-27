/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:28:08 by bexner            #+#    #+#             */
/*   Updated: 2021/05/28 22:40:56 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**NAME
* ft_lstadd_front
**Synopsis
* #include "libft.h"
**Prototype
* void ft_lstadd_front(t_list **lst, t_list *new)
**Arguments
* t_list **lst -> Adress of pointer to first Element of List
* t_list *new -> Adress of pointer to new Element
** Description
* Adds the *new Value at the Beginning of the **List
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
