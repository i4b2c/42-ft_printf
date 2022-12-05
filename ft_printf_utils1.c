/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:41:40 by icaldas           #+#    #+#             */
/*   Updated: 2022/12/05 12:44:05 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int i, int fd)
{
	if (i <= 9)
	{
		ft_putchar_fd(i + 48, fd);
		return ;
	}
	else
		ft_putunbr_fd(i / 10, fd);
	ft_putunbr_fd(i % 10, fd);
}

int	ft_hexa(unsigned int n)
{
	int	i;

	i = ft_lenhexa(n);
	if (n == 0)
		i = 1;
	if (n >= 16)
	{
		ft_hexa(n / 16);
		ft_hexa(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n + 'a' - 10, 1);
	}
	return (i);
}

int	ft_uphexa(unsigned int n)
{
	int	i;

	i = ft_lenhexa(n);
	if (n == 0)
		i = 1;
	if (n >= 16)
	{
		ft_uphexa(n / 16);
		ft_uphexa(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n + 'A' - 10, 1);
	}
	return (i);
}

int	ft_printnumb(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_unumlen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
