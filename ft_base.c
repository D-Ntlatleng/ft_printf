/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:26:42 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:27:08 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(unsigned long long n, char *ch)
{
	if (n == 0)
	{
		ch[0] = '0';
		ch[1] = 0;
	}
}

void		ft_base(unsigned long long n, char *ch, size_t base, size_t j)
{
	unsigned long	r_nbr;
	int				i;

	i = 0;
	if (n == 0)
	{
		check(n, ch);
		return ;
	}
	while (n)
	{
		r_nbr = n % base;
		if (r_nbr < 10)
			ch[i] = r_nbr + 48;
		else
		{
			if (j == 1)
				ch[i] = r_nbr + 87;
			else if (j == 0)
				ch[i] = r_nbr + 55;
		}
		n /= base;
		i++;
	}
	ft_strrev(ch);
}
