/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:56:52 by bexner            #+#    #+#             */
/*   Updated: 2021/06/17 22:30:31 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	if (num * size == 0)
		return (malloc(0));
	pointer = (unsigned char *)malloc(num * size);
	if (pointer == 0)
		return (NULL);
	while (i < (num * size))
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}
