/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:53:27 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/27 16:16:32 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcstr(t_flag *my)
{
	int i;

	i = ft_wstrlen(my->wstr);
	if (my->minus == 1)
	{
		while (*my->wstr)
			charector(*my->wstr++, my);
		while (my->width > i++)
			ft_putchar(32, my);
	}
	else
	{
		while (my->width-- > i)
			ft_putchar(32, my);
		while (*my->wstr)
			charector(*my->wstr++, my);
	}
}
