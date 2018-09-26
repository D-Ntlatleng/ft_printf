/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_con.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:02:20 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:12:40 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_con(char c, t_flag *my, va_list flags)
{
	if (c == '%')
		percent(my);
	else if (c == 'd' || c == 'i' || c == 'D')
		dec_check(my, flags);
	else if (c == 's' || c == 'S')
		str_check(my, flags, c);
	else if (c == 'p')
		pointer(my, va_arg(flags, unsigned long));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			my->x++;
		hex_check(my, flags, 16);
	}
	else if (c == 'o' || c == 'O')
		octal_check(my, flags, 8);
	else if (c == 'u' || c == 'U')
		octal_check(my, flags, 10);
	else if (c == 'c' || c == 'C')
		char_check(my, flags, c);
	return (0);
}
