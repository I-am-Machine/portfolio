/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:05:43 by bexner            #+#    #+#             */
/*   Updated: 2021/06/22 08:58:48 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_new_str(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*SubString;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	SubString = malloc(len + 1);
	if (SubString == 0)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		SubString[i] = s[i + start];
		i++;
	}
	SubString[i] = '\0';
	return (SubString);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	n = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[n]))
		n--;
	return (ft_create_new_str(s1, 0, ++n));
}
