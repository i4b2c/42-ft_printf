#include "ft_printf.h"
#include <stdarg.h>

void	ft_putunbr_fd(unsigned int i, int fd)
{
	if (i <= 9)
	{
		ft_putchar_fd(i  + 48 , fd);
		return ;
	}
	else
		ft_putunbr_fd(i / 10, fd);
	ft_putunbr_fd(i % 10 , fd);
}

int ft_printf(char *str, ...)
{
	int i;
	char c;
	char *s;
	int nb;
	va_list args;
	unsigned int unb;

	i = 0;
	va_start(args,str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				c = va_arg(args, int);
				ft_putchar_fd(c,1);
			}
			if (str[i] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s,1);
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				nb = va_arg(args, int);
				ft_putnbr_fd(nb,1);
			}
			if (str[i] == 'u')
			{
				unb = va_arg(args, unsigned int);
				ft_putunbr_fd(unb,1);
			}
			if (str[i] == '%')
				ft_putchar_fd('%',1);

			i++;
		}
		else
		{
			ft_putchar_fd(str[i],1);
			i++;
		}
	}
	va_end(args);
	return (0);
}
/*
int main(void)
{
	char str = 'a';

	printf("%p",&str);
	return 0;

}*/
