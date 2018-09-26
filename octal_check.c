/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:42:58 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 14:56:35 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octal_check(t_flag *my, va_list flags, int base)
{
	my->base = base;
	if (my->l)
		my->uvalue = (unsigned long int)va_arg(flags, unsigned long long int);
	else if (my->ll)
		my->uvalue = va_arg(flags, unsigned long long int);
	else if (my->j)
		my->uvalue = (uintmax_t)va_arg(flags, unsigned long long int);
	else if (my->z)
		my->uvalue = (size_t)va_arg(flags, unsigned long long int);
	else if (my->h)
		my->uvalue = (unsigned short)va_arg(flags, unsigned long long int);
	else if (my->hh)
		my->uvalue = (unsigned char)va_arg(flags, unsigned long long int);
	else
		my->uvalue = (unsigned int)va_arg(flags, unsigned long long int);
	if (my->hash == 2)
		my->hash = 1;
	if (my->temp)
	{
		if (my->pre == -1)
			my->pre = 0;
	}
	octal(my);
}
