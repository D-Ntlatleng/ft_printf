/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:41:23 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:25:30 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision(const char *fmt, va_list flags, t_flag *my)
{
	if (ft_isdigit(*fmt))
	{
		my->pre = ft_atoi(fmt);
		return (move(fmt));
	}
	else if (*fmt == '*')
	{
		my->pre = va_arg(flags, unsigned int);
		return (1);
	}
	return (0);
}
