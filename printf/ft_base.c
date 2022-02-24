/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:51:55 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 13:23:25 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(long double num, char *content, t_print *count)
{
	unsigned long	base;
	int				i;

	i = 1;
	base = ft_strlen(content);
	if (num == 0)
	{
		ft_putchar('0', count);
		return (i);
	}
	if (num < 0)
	{
		ft_putchar('-', count);
		num = num *(-1);
	}
	if (num >= base)
	{
		i += ft_base(num / base, content, count);
		ft_putchar(content[(unsigned long)num % base], count);
	}
	else if (num < base)
		ft_putchar(content[(unsigned long)num], count);
	return (i);
}
