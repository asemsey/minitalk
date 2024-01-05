/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:04:54 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/05 16:27:03 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_to_int(const char *s)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (48 <= s[i] && s[i] <= 57)
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	res;

	i = 0;
	negative = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	if ('0' <= str[i] && str[i] <= '9')
	{
		res = ft_to_int(&str[i]);
		return (negative * res);
	}
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_cases(int nbr, int fd)
{
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == 0 || n == -2147483648)
	{
		ft_cases(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(fd, &str[i], 1);
	}
}
