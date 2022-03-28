/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:05:12 by bexner            #+#    #+#             */
/*   Updated: 2021/10/25 17:05:50 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	chr;

	chr = (char)c;
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	return ((char *) NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_count_size;
	int		i;

	total_count_size = count * size;
	ptr = malloc(total_count_size);
	if (!ptr)
		return (0);
	i = 0;
	while (total_count_size)
	{
		ptr[i] = 0;
		i++;
		total_count_size--;
	}
	return ((void *) ptr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;

	dst2 = (char *) dst;
	src2 = (char *) src;
	if (dst == src)
		return (dst);
	if (src2 < dst2)
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
		return (dst);
	}
	while (len--)
		*dst2++ = *src2++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (s3 == 0)
		return (NULL);
	while (s1[i])
	{
		s3[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		s3[j] = s2[i];
		j++;
		i++;
	}
	if (s2[i] == '\n')
		s3[j] = '\n';
	return (s3);
}
