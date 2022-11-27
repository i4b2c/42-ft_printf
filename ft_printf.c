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

void	ft_hexa(int n)
{
	char str[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

	ft_putchar_fd(str[n / 16],1);
	ft_putchar_fd(str[n % 16],1);
}

void	ft_uphexa(int n)
{
	char str[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	ft_putchar_fd(str[n / 16],1);
	ft_putchar_fd(str[n % 16],1);
}

int ft_printf(char *str, ...)
{
	int i;
	int h;
	char c;
	char *s;
	int nb;
	va_list args;
	unsigned int unb;
	int contagem;

	i = 0;
	contagem = 0;
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
				contagem++;
			}
			if (str[i] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s,1);
				contagem += ft_strlen(s);
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				nb = va_arg(args, int);
				ft_putnbr_fd(nb,1);
				contagem += ft_strlen(ft_itoa(nb));
			}
			if (str[i] == 'u')
			{
				unb = va_arg(args, unsigned int);
				ft_putunbr_fd(unb,1);
				contagem += ft_strlen(ft_itoa(nb));
			}
			if (str[i] == 'x')
			{
				h = va_arg(args, int);
				ft_hexa(h);
				contagem += 2;
			}
			if (str[i] == 'X')
			{
				h = va_arg(args , int);
				ft_uphexa(h);
				contagem += 2;
			}
			if (str[i] == '%')
			{
				ft_putchar_fd('%',1);
				contagem++;
			}
			i++;
		}
		else
		{
			ft_putchar_fd(str[i],1);
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
	char a = 126;
	int i;

	i = printf("%c%s%d%i%u%x%X%%\n",'o',"i como vai ? ->",5,5,5,126,126);
	ft_printf("quantidade de letras: %d\n",i);
	i = 0;
	i = ft_printf("%c%s%d%i%u%x%X%%\n",'o',"i como vai ? ->",5,5,5,126,126);
	ft_printf("quantidade de letras: %d\n",i);
	return 0;

}*/
