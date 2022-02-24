/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:54:04 by bexner            #+#    #+#             */
/*   Updated: 2021/06/11 12:01:03 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* It allocates memory and returns a concatinated string
* NULL if Allocation fails
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		s1len;
	int		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3 = (char *)malloc(s1len + s2len + 1);
	if (s3 == 0)
		return (NULL);
	ft_memcpy(s3, s1, s1len);
	ft_memcpy(s3 + s1len, s2, s2len);
	*(s3 + s1len + s2len) = '\0';
	return (s3);
}
