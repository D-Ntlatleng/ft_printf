/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:01:35 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:12:23 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	test2(int s)
{
	int i;

	i = 0;
	if (s <= 127)
		i++;
	else if (s <= 2047)
		i += 2;
	else if (s <= 65535)
		i += 3;
	else if (s <= 1114111)
		i += 4;
	return (i);
}

static void	space(t_flag *my, int s)
{
	int i;
	int j;

	i = 0;
	j = test2(s);
	while (i++ + j < my->width)
		ft_putchar(32, my);
}

void		char_check(t_flag *my, va_list flags, char c)
{
	int s;

	s = va_arg(flags, int);
	if (my->minus)
	{
		if (my->l || c == 'C')
			charector(s, my);
		else
			ft_putchar(s, my);
		space(my, s);
	}
	else
	{
		space(my, s);
		if (my->l || c == 'C')
			charector(s, my);
		else
			ft_putchar(s, my);
	}
}
