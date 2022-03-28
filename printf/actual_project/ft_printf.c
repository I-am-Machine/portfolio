/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:30:14 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 13:22:41 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_initialise_count(t_print *count)
{
	count->total_len = 0;
	return (count);
}

void	ft_format_specifiers(t_print *x, const char *str, int i)
{
	double			nr;
	unsigned int	o;
	unsigned int	l;
	char			c;
	unsigned int	p;

	if (str[i] == '%')
	{
		if (str[i + 1] == 'c')
			ft_putchar(c = va_arg(x->args, int), x);
		else if (str[i + 1] == 's')
			ft_print_string(x);
		else if (str[i + 1] == 'p')
			ft_print_voidpointer(x);
		else if (str[i + 1] == 'd' || str[i + 1] == 'i')
			ft_base(nr = va_arg(x->args, int), "0123456789", x);
		else if (str[i + 1] == 'u')
			ft_base(p = va_arg(x->args, unsigned int), "0123456789", x);
		else if (str[i + 1] == 'x')
			ft_base(o = va_arg(x->args, unsigned int), "0123456789abcdef", x);
		else if (str[i + 1] == 'X')
			ft_base(l = va_arg(x->args, unsigned int), "0123456789ABCDEF", x);
		else if (str[i + 1] == '%')
			ft_putchar('%', x);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	t_print	*count;

	count = (t_print *)malloc(sizeof(t_print));
	if (!count)
		return (-1);
	ft_initialise_count(count);
	va_start(count->args, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_format_specifiers(count, str, i++);
		else
			ft_putchar(str[i], count);
		i++;
	}
	va_end(count->args);
	counter += count->total_len;
	free(count);
	return (counter);
}
