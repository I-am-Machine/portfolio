/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:23:14 by bexner            #+#    #+#             */
/*   Updated: 2021/11/29 13:23:07 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		total_len;
}	t_print;

int		ft_printf(const char *str, ...);
t_print	*ft_initialise_tab(t_print *count);
int		ft_base(long double num, char *content, t_print *count);
void	ft_putchar(char c, t_print *count);
char	*ft_uitoa(unsigned int number);
void	ft_print_voidpointer(t_print *count);
void	ft_print_string(t_print *count);
void	ft_print_int(int number);
int		ft_numberlength(long number);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *s, int c, size_t n);

#endif
