/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pristr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:49:19 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/27 14:53:08 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(t_flag *my)
{
	int j;

	j = ft_strlen(my->str);
	if (my->temp)
	{
		if (my->pre > j)
			my->pre = j;
	}
	else
		my->pre = j;
}

void		pristr(t_flag *my)
{
	int i;

	i = 0;
	check(my);
	if (my->minus == 1)
	{
		while (i < my->pre)
			ft_putchar(my->str[i++], my);
		while (i++ < my->width)
			ft_putchar(32, my);
	}
	else
	{
		while (my->pre < my->width--)
			ft_putchar(32, my);
		while (i < my->pre)
			ft_putchar(my->str[i++], my);
	}
}
