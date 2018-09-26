/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:02:38 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/28 13:02:04 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_check(t_flag *my, va_list flags, char c)
{
	if (my->temp)
	{
		if (my->pre == -1)
			my->pre = 0;
	}
	if (my->l || c == 'S')
	{
		my->wstr = va_arg(flags, wchar_t *);
		if (my->wstr == NULL)
			my->wstr = L"(null)";
		if (my->temp == 0)
			ft_putcstr(my);
		else if (my->temp == 1)
			ft_putwstr(my);
	}
	else
	{
		my->str = va_arg(flags, char *);
		if (my->str == NULL)
			my->str = "(null)";
		pristr(my);
	}
}
