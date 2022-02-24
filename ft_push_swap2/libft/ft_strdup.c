/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:18:16 by bexner            #+#    #+#             */
/*   Updated: 2021/06/11 12:00:55 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	strlen;
	size_t	i;

	dest = NULL;
	i = 0;
	strlen = 0;
	while (s[strlen] != '\0')
	{
		strlen++;
	}
	dest = (char *)malloc(strlen + 1);
	if (dest == 0)
		return (NULL);
	while (s[i])
	{
		dest[i] = ((char *)s)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
