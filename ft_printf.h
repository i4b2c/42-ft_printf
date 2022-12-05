/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:26:21 by icaldas           #+#    #+#             */
/*   Updated: 2022/12/05 11:28:38 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		print_n_cont(va_list args, char ch);
int		ft_pointer(void *s);
char	ft_ptr_hexa(int n);
char	*ft_strcpy(char *s, char *c);
int		ft_uphexa(unsigned int n);
int		ft_hexa(unsigned int n);
void	ft_putunbr_fd(unsigned int i, int fd);
int		ft_lenhexa(unsigned int n);
int		ptrlen(void *p);
int		ft_printstr(char *s);
int		ft_putchar_rint(int i);
char	*ft_uitoa(unsigned int n);
int		ft_printuinumb(unsigned int n);
int		ft_unumlen(unsigned int n);
int		ft_printnumb(int n);
char	ft_ptr_hexa(int n);

#endif
