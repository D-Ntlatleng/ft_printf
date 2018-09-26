/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:31:29 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/28 12:56:11 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	test(unsigned long s)
{
	int i;

	i = 0;
	if (s <= 127)
		i = 1;
	else if (s <= 2047)
		i = 2;
	else if (s <= 65535)
		i = 3;
	else if (s <= 1114111)
		i = 4;
	return (i);
}

static void	check2(wchar_t *s, t_flag *my)
{
	int j;

	j = 0;
	while (*s)
	{
		if (my->pre >= (j += test(*s)))
			my->hash++;
		s++;
	}
}

static void	check(t_flag *my)
{
	int j;

	j = ft_wstrlen(my->wstr);
	if (my->temp)
	{
		if (my->pre >= j)
			my->hash = j;
		else
			check2(my->wstr, my);
	}
	else
		my->pre = j;
}

static void	minus(t_flag *my)
{
	int i;

	i = 0;
	while (my->hash-- > 0 && *my->wstr)
	{
		charector((unsigned int)*my->wstr, my);
		i += test(*my->wstr);
		my->wstr++;
	}
	while (i++ < my->width)
		ft_putchar(32, my);
}

void		ft_putwstr(t_flag *my)
{
	int i;
	int j;

	i = 0;
	j = 0;
	check(my);
	if (my->minus == 1)
		minus(my);
	else
	{
		while (j < my->hash && my->wstr[j])
			i += test(my->wstr[j++]);
		while (i++ < my->width)
			ft_putchar(32, my);
		while (my->hash-- > 0 && *my->wstr)
		{
			charector((unsigned int)*my->wstr, my);
			my->wstr++;
		}
	}
}
