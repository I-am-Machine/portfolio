/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:10:47 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 12:27:29 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int number)
{
	char	*str;
	int		len;

	len = ft_numberlength(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (number == 0)
		str[len] = 0 + '0';
	while (number > 0)
	{
		str[len--] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}
