/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:00:46 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 12:07:47 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup(const char *s)
{
	char		*str;
	size_t		len;

	str = NULL;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (ft_strlcpy(str, s, len + 1) == len)
		return (str);
	else
		return (NULL);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ret;

	ret = NULL;
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (ret);
	ft_memset(ret, 0, nmemb * size);
	return (ret);
}

static char	*ft_convert(int n, int digit_len, int is_neg)
{
	char	*ptr_to_str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (is_neg == 1)
		j++;
	while (i <= n / 10)
	{
		digit_len++;
		i = i * 10;
	}
	ptr_to_str = ft_calloc((digit_len + 1), sizeof(char));
	if (!ptr_to_str)
		return (NULL);
	while (digit_len > 0 && i != 0)
	{
		ptr_to_str[j] = (n / i) + '0';
		n = n % i;
		i = i / 10;
		digit_len--;
		j++;
	}
	return (ptr_to_str);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		digit_len;
	char	*str;

	digit_len = 1;
	is_neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		is_neg = 1;
		digit_len++;
	}
	str = ft_convert(n, digit_len, is_neg);
	if (!str)
		return (NULL);
	if (is_neg == 1)
		*str = '-';
	return (str);
}
