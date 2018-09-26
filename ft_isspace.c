/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:27:08 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:15:17 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}