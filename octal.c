/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:45:49 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 16:59:45 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero(t_flag *my)
{
	char ch[my->l + 1];

	ft_bzero(ch, my->l + 1);
	if (my->uvalue && my->hash)
		ft_putchar('0', my);
	if (!my->pre && !my->uvalue && my->hash)
		ft_putchar('0', my);
	while (my->width > my->plus++)
		ft_putchar('0', my);
	if (!(my->pre == 0 && my->uvalue == 0))
	{
		ft_base(my->uvalue, ch, my->base, my->x);
		ft_putstr(ch, my);
	}
}

static void	minus(t_flag *my)
{
	char ch[my->l + 1];

	ft_bzero(ch, my->l + 1);
	if (my->uvalue && my->hash)
		ft_putchar('0', my);
	if (!my->pre && !my->uvalue && my->hash)
		ft_putchar('0', my);
	while (my->pre > my->l++)
		ft_putchar('0', my);
	if (!(my->pre == 0 && my->uvalue == 0))
	{
		ft_base(my->uvalue, ch, my->base, my->x);
		ft_putstr(ch, my);
	}
	while (my->width > my->plus++)
		ft_putchar(32, my);
}

static void	no_minus(t_flag *my)
{
	char ch[my->l + 1];

	ft_bzero(ch, my->l + 1);
	while (my->width > my->plus++)
		ft_putchar(32, my);
	if (my->uvalue && my->hash)
		ft_putchar('0', my);
	if (!my->pre && !my->uvalue && my->hash)
		ft_putchar('0', my);
	while (my->pre > my->l++)
		ft_putchar('0', my);
	if (!(my->pre == 0 && my->uvalue == 0))
	{
		ft_base(my->uvalue, ch, my->base, my->x);
		ft_putstr(ch, my);
	}
}

static void	check(t_flag *my)
{
	my->l = 0;
	if (my->temp)
	{
		if (my->pre == 1)
			my->pre = 0;
	}
	if (!(my->pre == 0 && my->uvalue == 0))
	{
		my->plus = fsize(my->uvalue, my->base);
		my->l = my->plus;
	}
	if (my->pre > my->plus)
		my->plus = my->pre;
	if (my->hash)
		my->plus += 1;
}

void		octal(t_flag *my)
{
	check(my);
	if (my->zero && !my->temp && !my->minus)
		zero(my);
	else
	{
		if (my->minus)
			minus(my);
		else
			no_minus(my);
	}
}
