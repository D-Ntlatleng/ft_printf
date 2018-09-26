/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:13:45 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/27 10:33:45 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	stru_in(t_flag *my)
{
	my->sp = 0;
	my->minus = 0;
	my->plus = 0;
	my->zero = 0;
	my->hash = 0;
	my->h = 0;
	my->hh = 0;
	my->l = 0;
	my->ll = 0;
	my->j = 0;
	my->z = 0;
	my->width = -1;
	my->pre = -1;
	my->x = 0;
	my->temp = 0;
}

static int	check(const char *fmt, va_list flags, t_flag *my)
{
	int i;

	i = 0;
	stru_in(my);
	i += ft_flags(&fmt[i], my);
	i += width(&fmt[i], flags, my);
	if (fmt[i] == '.')
	{
		my->temp = 1;
		i++;
		i += precision(&fmt[i], flags, my);
	}
	i += ft_length(&fmt[i], my);
	if (ft_strchr("sSpdDioOuUxXcC%", fmt[i]))
		char_con(fmt[i++], my, flags);
	return (i);
}

int			ft_printf(const char *fmt, ...)
{
	int		i;
	t_flag	my;
	va_list	flags;

	va_start(flags, fmt);
	i = 0;
	my.ans = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			i += check(&fmt[i], flags, &my);
		}
		else
			ft_putchar(fmt[i++], &my);
	}
	va_end(flags);
	return (my.ans);
}
