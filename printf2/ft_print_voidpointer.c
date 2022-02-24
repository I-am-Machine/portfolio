/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:06:12 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 13:22:58 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_voidpointer(t_print *count)
{
	unsigned long	number;

	number = (unsigned long)va_arg(count->args, void *);
	count->total_len += write(1, "0x", 2);
	ft_base(number, "0123456789abcdef", count);
}
