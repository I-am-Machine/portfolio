/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:06:41 by bexner            #+#    #+#             */
/*   Updated: 2021/06/22 08:59:47 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_counter;
	unsigned int	src_counter;
	size_t			srclen;
	unsigned int	dest_counter_original;

	srclen = ft_strlen(src);
	dest_counter = 0;
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (dest[dest_counter] != '\0')
	{
		dest_counter++;
		if (dest_counter >= size)
			return (size + srclen);
	}
	dest_counter_original = dest_counter;
	src_counter = 0;
	while (src[src_counter] != '\0' && dest_counter < size - 1)
	{	
		dest[dest_counter] = src[src_counter];
		dest_counter++;
		src_counter++;
	}
	dest[dest_counter] = '\0';
	return (dest_counter_original + srclen);
}
