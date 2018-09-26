/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:23:18 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/27 10:26:28 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unicode2(unsigned int code, char *temp)
{
	if (code <= 0x10FFFF)
	{
		temp[3] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[2] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[1] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[0] = 0xF0 | (code & 0x7);
		temp[4] = '\0';
	}
	else
	{
		temp[2] = 0xEF;
		temp[1] = 0xBF;
		temp[0] = 0xBD;
		temp[3] = '\0';
	}
}

static void	unicode(unsigned int code, char *temp)
{
	if (code <= 0x7F)
	{
		temp[0] = (code & 0x7F);
		temp[1] = '\0';
	}
	else if (code <= 0x7FF)
	{
		temp[1] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[0] = 0xC0 | (code & 0x1F);
		temp[2] = '\0';
	}
	else if (code <= 0xFFFF)
	{
		temp[2] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[1] = 0x80 | (code & 0x3F);
		code = (code >> 6);
		temp[0] = 0xE0 | (code & 0xF);
		temp[3] = '\0';
	}
	else
		unicode2(code, temp);
}

void		charector(unsigned int code, t_flag *my)
{
	int		i;
	char	temp[10];

	i = 0;
	ft_bzero(temp, 10);
	unicode(code, temp);
	while (i < 10 && temp[i])
		write(1, &temp[i++], 1);
	if (code <= 127)
		my->ans++;
	else if (code <= 2047)
		my->ans += 2;
	else if (code <= 65535)
		my->ans += 3;
	else if (code <= 1114111)
		my->ans += 4;
}
