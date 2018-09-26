/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:37:33 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:14:04 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	test(unsigned long ans, int s, unsigned long j)
{
	if (ans > INT_MAX && s == 1)
		return (-1);
	if (ans > INT_MAX && j < LONG_MAX && s == -1)
		return (1);
	if (ans >= LONG_MAX && s == -1)
		return (0);
	return (3);
}

int			ft_atoi(const char *str)
{
	unsigned long	ans;
	int				s;
	unsigned long	j;

	ans = 0;
	s = 1;
	j = ans - 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str) && *str != '\0')
	{
		ans = ans * 10 + (*str++ - '0');
		if (test(ans, s, j) == -1 || test(ans, s, j) == 1 ||
				test(ans, s, j) == 0)
			return (test(ans, s, j));
	}
	return ((int)ans * s);
}
