/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:56:55 by bexner            #+#    #+#             */
/*   Updated: 2021/06/17 21:55:53 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	while (n--)
	{
		*dest2++ = *src2++;
	}
	return (dest);
}
