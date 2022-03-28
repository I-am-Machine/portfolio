/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:23:11 by bexner            #+#    #+#             */
/*   Updated: 2021/05/28 23:33:51 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *contentinput)
{
	t_list	*output;

	output = (t_list *) malloc(sizeof(t_list));
	output -> content = contentinput;
	output -> next = NULL;
	return (output);
}
