/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:14:31 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:24:55 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put(char c, int n, t_flag *my)
{
	int i;

	i = 1;
	while (i++ < n)
		ft_putchar(c, my);
}

void		percent(t_flag *my)
{
	if (my->minus == 1)
	{
		ft_putchar('%', my);
		put(32, my->width, my);
	}
	else if (my->zero == 1)
	{
		put('0', my->width, my);
		ft_putchar('%', my);
	}
	else
	{
		put(32, my->width, my);
		ft_putchar('%', my);
	}
}
