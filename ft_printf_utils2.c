/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:32:35 by icaldas           #+#    #+#             */
/*   Updated: 2022/12/05 12:32:37 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuinumb(unsigned int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		ft_putchar_fd('0',1);
		return(1);
	}
	str = ft_uitoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str,1);
	free (str);
	return (len);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)",1);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i],1);
		i++;
	}
	return (i);
}

int	ft_putchar_rint(int i)
{
	ft_putchar_fd(i,1);
	return (1);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unumlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
