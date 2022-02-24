/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:35:13 by bexner            #+#    #+#             */
/*   Updated: 2022/01/11 15:47:13 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int spid, char *str)
{
	size_t	string_len;
	size_t	i;
	int		bit;

	if (!str)
		return ;
	string_len = ft_strlen(str);
	str[string_len] = '\0';
	i = 0;
	while (i <= string_len)
	{
		bit = 0;
		while (bit <= 7)
		{
			if (str[i] >> bit & 1)
				kill(spid, SIGUSR2);
			else
				kill(spid, SIGUSR1);
			bit++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_message(ft_atoi(argv[1]), argv[2]);
	else
		ft_print_str("Invalid Input. Please use the Ascii Table.");
	return (0);
}
