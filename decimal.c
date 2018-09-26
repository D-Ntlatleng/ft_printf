/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:01:54 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 14:48:33 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero(t_flag *my)
{
	if (my->sp && my->plus == 0 && my->value >= 0)
		ft_putchar(32, my);
	else if (my->plus && my->value >= 0)
		ft_putchar('+', my);
	else if (my->value < 0)
		ft_putchar('-', my);
	while (my->width > my->hash++)
		ft_putchar('0', my);
	ft_putnbr(my->value, my);
}

static void	minus(t_flag *my)
{
	if (my->sp && my->plus == 0 && my->value >= 0)
		ft_putchar(32, my);
	else if (my->plus && my->value >= 0)
		ft_putchar('+', my);
	else if (my->value < 0)
		ft_putchar('-', my);
	while (my->pre > my->l++)
		ft_putchar('0', my);
	if (!(my->pre == 0 && my->value == 0))
		ft_putnbr(my->value, my);
	while (my->width > my->hash++)
		ft_putchar(32, my);
}

static void	no_minus(t_flag *my)
{
	while (my->width > my->hash++)
		ft_putchar(32, my);
	if (my->sp && my->plus == 0 && my->value >= 0)
		ft_putchar(32, my);
	else if (my->plus && my->value >= 0)
		ft_putchar('+', my);
	else if (my->value < 0)
		ft_putchar('-', my);
	while (my->pre > my->l++)
		ft_putchar('0', my);
	if (!(my->pre == 0 && my->value == 0))
		ft_putnbr(my->value, my);
}

static void	check(t_flag *my)
{
	my->l = 0;
	if (my->temp)
	{
		if (my->pre == -1)
			my->pre = 0;
	}
	if (!(my->pre == 0 && my->value == 0))
	{
		if (my->value < 0)
			my->hash = fsize(-1 * my->value, 10);
		else
			my->hash = fsize(my->value, 10);
		my->l = my->hash;
	}
	if (my->pre > my->hash)
		my->hash = my->pre;
	if (my->sp && my->plus == 0 && my->value > 0)
		my->hash += 1;
	else if (my->value < 0)
		my->hash += 1;
	else if (my->plus && my->value > 0)
		my->hash += 1;
}

void		decimal(t_flag *my)
{
	check(my);
	if (my->value == LONG_MIN)
		ft_putnbr(LONG_MIN, my);
	else if (my->zero && !my->temp && !my->minus)
		zero(my);
	else
	{
		if (my->minus)
			minus(my);
		else
			no_minus(my);
	}
}
