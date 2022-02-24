/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:44:18 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 12:25:07 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_print *count)
{
	int		j;
	char	*string;

	string = va_arg(count->args, char *);
	if (!string)
	{
		string = "(null)";
	}
	j = 0;
	while (string[j])
	{
		ft_putchar(string[j], count);
		j++;
	}
}
