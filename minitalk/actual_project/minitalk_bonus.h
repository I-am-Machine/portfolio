/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:15:47 by bexner            #+#    #+#             */
/*   Updated: 2022/01/11 15:32:29 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_print_str(char *str);
void	ft_print_char(char c);
size_t	ft_strlen(char *str);
void	ft_print_nbr(int nbr);
int		ft_atoi(const char *str);

#endif