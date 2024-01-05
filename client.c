/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:53:01 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/05 16:33:36 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// displays a message when the server sends a response
void	client_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "message received\n", 18);
		exit(EXIT_SUCCESS);
	}
}

// sends a string to a process in binary 
// (SIGUSR1 == 1, SIGUSR2 == 0) then a null character
void	send(unsigned char *str, int pid)
{
	unsigned char	bit;

	bit = 0;
	while (str && *str)
	{
		bit = 128;
		while (bit > 0)
		{
			if (*str & bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit /= 2;
			usleep(90);
		}
		str++;
	}
	while (bit < 8)
	{
		kill(pid, SIGUSR2);
		bit++;
		usleep(90);
	}
}

int	main(int argc, char const *argv[])
{
	pid_t				server_id;
	struct sigaction	sa;

	if (argc != 3 || !ft_atoi(argv[1]))
		return (EXIT_FAILURE);
	sa.sa_handler = client_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	server_id = ft_atoi(argv[1]);
	send((unsigned char *)argv[2], server_id);
	while (1)
		pause();
}
