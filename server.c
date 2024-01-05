/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:53:11 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/05 11:31:23 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static unsigned char	bit;
	static unsigned char	c;

	if (bit == 0)
		bit = 128;
	if (sig == SIGUSR1)
		c += bit;
	bit /= 2;
	if (bit == 0)
	{
		// if (c == 0)
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	// printf("%d\n", id);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
