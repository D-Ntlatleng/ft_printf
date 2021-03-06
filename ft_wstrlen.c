/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:20:15 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/28 13:00:18 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(const wchar_t *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s <= 127)
			i += 1;
		else if (*s <= 2047)
			i += 2;
		else if (*s <= 65535)
			i += 3;
		else if (*s <= 1114111)
			i += 4;
		s++;
	}
	return (i);
}
