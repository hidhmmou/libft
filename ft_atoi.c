/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:43:54 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/10/08 23:09:38 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\v'
		|| c == '\n'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_isnum(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	unsigned long long	s;
	int		sign;

	i = 0;
	s = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isnum(str[i]))
	{
		s = s * 10 + (str[i] - '0');
		i++;
		if (s * sign < LLONG_MAX)
			return (0);
		if (s * sign > LLONG_MIN)
			return (-1);
	}
	return (sign * s);
}
