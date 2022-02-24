/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:15:51 by bexner            #+#    #+#             */
/*   Updated: 2022/01/11 16:16:08 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_message(int sig, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1 || sig == SIGUSR2)
		kill(siginfo->si_pid, SIGUSR1);
	if (sig == SIGUSR1)
		c += (0 << i);
	if (sig == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_print_char('\n');
			i = 0;
			c = 0;
		}
		ft_print_char(c);
		i = 0;
		c = 0;
	}
	(void)context;
	(void)siginfo;
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &handle_message;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	ft_print_str("The Servcer PID is: ");
	ft_print_nbr(getpid());
	ft_print_char('\n');
	while (1)
		pause();
	return (0);
}
