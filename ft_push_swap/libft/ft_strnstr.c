/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:10:25 by bexner            #+#    #+#             */
/*   Updated: 2021/06/22 08:59:23 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	b;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (!src || !srclen)
		return ((char *)dest);
	while (i < n && dest[i])
	{
		b = 0;
		while (src[b] == dest[b + i] && src[b]
			&& dest[i + b] && i + b < n && b < srclen)
			b++;
		if (b == srclen)
			return ((char *)dest + i);
		i++;
	}
	return (0);
}
