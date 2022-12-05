/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:23:11 by icaldas           #+#    #+#             */
/*   Updated: 2022/12/05 12:25:05 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhexa(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

int	ptrlen(void *p)
{
	int		i;
	uintptr_t	c;

	c = (uintptr_t)p;
	i = 0;
	while (c / 16 != 0)
	{
		c = c / 16;
		i++;
	}
	return (++i);
}
