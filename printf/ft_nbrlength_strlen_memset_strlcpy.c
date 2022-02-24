/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlength_strlen_memset_strlcpy.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:17 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 12:23:54 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numberlength(long number)
{
	int	i;

	i = 0;
	if (number <= 0)
	{
		i++;
		number = number * -1;
	}
	while (number > 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (*src != '\0' && dstsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char		*i;

	i = NULL;
	i = s;
	while (n > 0)
	{
		*i = c;
		i++;
		n--;
	}
	return (s);
}
