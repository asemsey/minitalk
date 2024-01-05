/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:53:01 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/05 11:31:56 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(unsigned char c, int pid)
{
	unsigned char	i;

	i = 128;
	while (i > 0)
	{
		if (c & i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i /= 2;
		usleep(90);
	}
}

int	main(int argc, char const *argv[])
{
	pid_t	id;
	pid_t	client_id;
	int		i;

	id = 0;
	i = 0;
	client_id = getpid();
	if (argc == 3 && ft_isnum(argv[1]))
	{
		id = ft_atoi(argv[1]);
		while (argv[2] && argv[2][i])
		{
			send((unsigned char)argv[2][i], id);
			i++;
		}
	}
	return (0);
}
