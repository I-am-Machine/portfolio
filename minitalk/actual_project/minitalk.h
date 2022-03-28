/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 22:52:48 by bexner            #+#    #+#             */
/*   Updated: 2022/01/11 15:32:11 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_print_str(char *str);
void	ft_print_char(char c);
size_t	ft_strlen(char *str);
void	ft_print_nbr(int nbr);
int		ft_atoi(const char *str);

#endif