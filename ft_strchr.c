/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:31:47 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/22 13:22:28 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	int		j;

	i = ft_strlen(str) + 1;
	j = 0;
	while (i)
	{
		if (c == str[j])
			return ((char *)str + j);
		i--;
		j++;
	}
	return (NULL);
}
