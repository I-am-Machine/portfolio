/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:24:52 by bexner            #+#    #+#             */
/*   Updated: 2022/01/23 16:26:27 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	cdst = dst;
	csrc = src;
	if (!cdst || !csrc)
		return (NULL);
	if (cdst > csrc)
	{
		while (len--)
		{
			*cdst++ = *csrc++;
		}
	}
	else
	{
		cdst = dst + (len - 1);
		csrc = src + (len - 1);
		while (len--)
		{
			*cdst-- = *csrc--;
		}
	}
	return (cdst);
}
