/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:19:53 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:26:11 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width(const char *fmt, va_list flags, t_flag *my)
{
	if (ft_isdigit(*fmt))
	{
		my->width = ft_atoi(fmt);
		return (move(fmt));
	}
	else if (*fmt == '*')
	{
		my->width = va_arg(flags, unsigned int);
		return (1);
	}
	else
		my->width = 0;
	return (0);
}
