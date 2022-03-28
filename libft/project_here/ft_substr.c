/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:18:08 by bexner            #+#    #+#             */
/*   Updated: 2021/06/17 22:32:23 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*  *s = String to create the Substring from
*  Start Index of the Substring = start
* maximum length of substring = len
* return value is NULL if Malloc fails
* Return the Substring if everything is fine
* Description: it Allocates with Malloc(3) and returns a substring from a
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*SubString;

	if (!s || start > ft_strlen(s))
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
