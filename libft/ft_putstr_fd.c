/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:39:08 by icaldas           #+#    #+#             */
/*   Updated: 2022/11/18 12:34:09 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s != '\0')
	{
		write(fd, &*s, 1);
		s++;
	}
}
/*
int main(void)
{
	ft_putstr_fd("boas",1);
	return 0;
}*/
