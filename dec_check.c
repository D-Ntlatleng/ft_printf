/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:15:26 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 14:47:20 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dec_check(t_flag *my, va_list flags)
{
	if (my->l)
		my->value = va_arg(flags, long int);
	else if (my->ll)
		my->value = va_arg(flags, long long int);
	else if (my->j)
		my->value = va_arg(flags, long long int);
	else if (my->z)
		my->value = va_arg(flags, size_t);
	else if (my->h)
		my->value = (short)va_arg(flags, int);
	else if (my->hh)
		my->value = (signed char)va_arg(flags, int);
	else
		my->value = va_arg(flags, int);
	decimal(my);
}
