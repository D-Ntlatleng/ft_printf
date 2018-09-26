/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:47:43 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:24:08 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		move(const char *fmt)
{
	int i;

	i = 0;
	while (fmt[i] && ft_isdigit(fmt[i]))
		i++;
	return (i);
}
