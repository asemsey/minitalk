/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:04:54 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/04 11:51:42 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isnum(const char *c)
{
	if (c && *c && *c == '-')
		c++;
	while (c && *c)
	{
		if ('0' > *c || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

static int	ft_isspace(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

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
	while (ft_isspace(str[i]) == 1)
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
