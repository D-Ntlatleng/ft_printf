/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:33:08 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:14:26 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(const char *fmt, t_flag *my)
{
	int i;

	i = 0;
	while (fmt[i] && ft_strchr(" -+0#", fmt[i]))
	{
		if (fmt[i] == 32)
			my->sp = 1;
		else if (fmt[i] == '-')
			my->minus = 1;
		else if (fmt[i] == '+')
			my->plus = 1;
		else if (fmt[i] == '0')
			my->zero = 1;
		else if (fmt[i] == '#')
			my->hash = 2;
		i++;
	}
	return (i);
}
