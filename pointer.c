/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:14:52 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:25:20 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer(t_flag *my, unsigned long a)
{
	int		j;
	int		i;
	char	ch[(i = fsize(a, 16)) + 1];

	ft_bzero(ch, i + 1);
	j = 0;
	if (!my->minus)
	{
		while (j++ + i + 2 < my->width)
			ft_putchar(32, my);
		ft_putstr("0x", my);
		ft_base(a, ch, 16, 1);
		ft_putstr(ch, my);
	}
	else if (my->minus)
	{
		ft_putstr("0x", my);
		ft_base(a, ch, 16, 1);
		ft_putstr(ch, my);
		while (j++ + i + 2 < my->width)
			ft_putchar(32, my);
	}
}
