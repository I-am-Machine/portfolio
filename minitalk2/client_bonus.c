/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:15:43 by bexner            #+#    #+#             */
/*   Updated: 2022/01/12 17:33:20 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
			usleep(200);
		}
		i++;
	}
}

void	handle_message(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1)
	{
		write(1, "Polo. Signal Recieved.", 23);
	}
	(void)context;
	(void)siginfo;
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &handle_message;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	if (argc == 3 && ft_atoi(argv[1]) > 0)
		send_message(ft_atoi(argv[1]), argv[2]);
	else
		ft_print_str("Invalid Input. Use ServerID and a String to send.");
	while (1)
		pause();
	return (0);
}
