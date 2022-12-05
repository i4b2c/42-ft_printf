/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:27:54 by icaldas           #+#    #+#             */
/*   Updated: 2022/12/05 12:57:55 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_ptr_hexa(int n)
{
	char	num[10];
	char	alf[6];

	num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	alf = {'a', 'b', 'c', 'd', 'e', 'f'};
	if (n <= 10)
		return (str[n]);
	else if (n > 10)
		return (alb[n - 11]);
}

int	ft_pointer(void *p)
{
	uintptr_t	c;
	char		*s ;
	int			i;
	int			len;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = ptrlen(p);
	len = i;
	s = malloc(sizeof(int) * i + 1);
	c = (uintptr_t)p;
	s[i--] = '\0';
	while (i >= 0)
	{
		s[i--] = ft_ptr_hexa(c % 16);
		c = c / 16;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(s, 1);
	free(s);
	return (len + 2);
}

int	print_n_cont(va_list args, char ch)
{
	int	i;

	i = 0;
	if (ch == 'c')
		i += ft_putchar_rint(va_arg(args, int));
	else if (ch == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (ch == 'i' || ch == 'd')
		i += ft_printnumb(va_arg(args, int));
	else if (ch == 'u')
		i += ft_printuinumb(va_arg(args, int));
	else if (ch == 'x')
		i += ft_hexa(va_arg(args, unsigned int));
	else if (ch == 'X')
		i += ft_uphexa(va_arg(args, unsigned int));
	else if (ch == 'p')
		i += ft_pointer(va_arg(args, void *));
	else if (ch == '%')
		i += ft_putchar_rint('%');
	else
		return (0);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		contagem;

	i = 0;
	contagem = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			contagem += print_n_cont(args, str[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			contagem++;
		}
	}
	va_end(args);
	return (contagem);
}
/*
int main(void)
{
	int i;

	i = ft_printf("%%%p\n",(void *)0);
	ft_printf("%d\n",i);
	i = printf("%%%p\n",(void *)0);
	printf("%d\n",i);
	return 0;

}*/
