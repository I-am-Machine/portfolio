/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:23:11 by bexner            #+#    #+#             */
/*   Updated: 2022/02/18 12:25:35 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *contentinput)
{
	t_listp	*output;

	output = (t_list *) malloc(sizeof(t_list));
	output -> content = contentinput;
	output -> next = NULL;
	return (output);
}
