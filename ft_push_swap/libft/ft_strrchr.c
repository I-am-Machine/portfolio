/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:31:45 by bexner            #+#    #+#             */
/*   Updated: 2021/06/01 01:07:03 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*c1;

	if (!s)
		return (NULL);
	i = 0;
	c1 = NULL;
	while (s[i])
	{
		if (s[i] == c)
			c1 = (char *)s + i;
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	else if (s[i] == c)
		c1 = (char *)s + i;
	return (c1);
}
