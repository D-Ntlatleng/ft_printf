/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:34:32 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:15:45 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(const char *fmt, t_flag *my, int i)
{
	if (fmt[i] == 'h' && fmt[i + 1] != 'h')
		my->h = 1;
	else if (fmt[i] == 'h' && fmt[i + 1] == 'h')
	{
		my->hh = 1;
		i++;
	}
	else if (fmt[i] == 'l' && fmt[i + 1] != 'l')
		my->l = 1;
	else if (fmt[i] == 'l' && fmt[i + 1] == 'l')
	{
		my->ll = 1;
		i++;
	}
	else if (fmt[i] == 'j')
		my->j = 1;
	else if (fmt[i] == 'z')
		my->z = 1;
	return (i);
}

int			ft_length(const char *fmt, t_flag *my)
{
	int i;

	i = 0;
	while (ft_strchr("hljz", fmt[i]) && fmt[i])
	{
		i += len(fmt, my, i);
		i++;
	}
	return (i);
}
