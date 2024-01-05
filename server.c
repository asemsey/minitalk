/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:53:11 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/05 16:41:59 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	bit;
	static unsigned char	c;

	(void)context;
	if (bit == 0)
		bit = 128;
	if (sig == SIGUSR1)
		c += bit;
	bit /= 2;
	if (bit == 0)
	{
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	pid_t				id;
	struct sigaction	sa;

	sa.sa_sigaction = server_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	id = getpid();
	write(1, "PID:   ", 8);
	ft_putnbr_fd(id, 1);
	write(1, "\n", 1);
	while (1)
		pause();
}
