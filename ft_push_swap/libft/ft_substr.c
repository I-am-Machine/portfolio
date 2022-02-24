/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:18:08 by bexner            #+#    #+#             */
/*   Updated: 2022/01/23 16:28:44 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  *s = String to create the substring from
*  Start Index of the substring = start
* maximum length of substring = len
* return value is NULL if Malloc fails
* Return the substring if everything is fine
* Description: it Allocates with Malloc(3) and returns a substring from a
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	substring = malloc(len + 1);
	if (substring == 0)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
