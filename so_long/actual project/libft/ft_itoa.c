/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:13:33 by bexner            #+#    #+#             */
/*   Updated: 2021/05/29 12:50:06 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoabody(int n, int neg, int len, int i)
{
	char	*result;
	int		orig;

	orig = n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	result = malloc(len + 1);
	i = len - 1;
	while (orig)
	{
		result[i] = (orig % 10) + '0';
		orig = orig / 10;
		i--;
	}
	if (neg == 1)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	int		neg;
	char	*result;

	len = 0;
	neg = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = n * (-1);
		len++;
		neg = 1;
	}
	result = ft_itoabody(n, neg, len, i);
	return (result);
}
