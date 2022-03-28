/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_line_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:24:52 by bexner            #+#    #+#             */
/*   Updated: 2022/03/28 13:55:08 by bexner           ###   ########.fr       */
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

int	line_len(t_data *mew, char *line, int index, int i)
{
	static int		line_len;

	if (line_len == 0)
		line_len = mew->rows;
	if (mew->rows < line_len || mew->rows > line_len)
		return (1);
	while (index < mew->rows)
	{
		mew->map[i][index] = line[index];
		index++;
	}
	return (0);
}
