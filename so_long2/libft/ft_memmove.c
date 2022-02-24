/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:38:04 by bexner            #+#    #+#             */
/*   Updated: 2021/06/04 11:08:22 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// learn memmove before turn in
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;
	char		*last_d;
	const char	*last_s;

	if (!dest || !src)
		return (NULL);
	dest2 = dest;
	src2 = src;
	if (dest2 < src2)
	{
		while (n--)
			*dest2++ = *src2++;
	}
	else
	{
		last_s = src2 + (n - 1);
		last_d = dest2 + (n - 1);
		while (n--)
			*last_d-- = *last_s--;
	}
	return (dest);
}
