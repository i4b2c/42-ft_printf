#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>

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

char *ft_strcpy(char *s, char *c)
{
	int i;
	i = 0;
	while(c[i] != '\0')
	{
		s[i] = c[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
		
char	ft_ptr_hexa(int n)
{
	char str[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

	return (str[n]);
}

void	ft_pointer(void * p)
{
	uintptr_t c;
	char s[12];
	int i;

	i = 11;
	c = (uintptr_t)p;
	while((c / 16) != 0)
	{
		s[i] = ft_ptr_hexa(c % 16);
		c = c / 16;
		i--;
	}
	ft_putchar_fd('0',1);
	ft_putchar_fd('x',1);
	s[i] = ft_ptr_hexa(c);
	ft_putstr_fd(s,1);
}

int	print_n_cont(va_list args, char ch)
{
	int n;
	unsigned int un;
	char *s;
	void *p;

	if(ch == 'c')
	{
		n = va_arg(args, int);
		ft_putchar_fd((char)n,1);
		return (1);
	}
	else if (ch == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s,1);
		return (ft_strlen(s));
	}
	else if (ch == 'i' || ch == 'd')
	{
		n = va_arg(args, int);
		ft_putnbr_fd(n,1);
		return (ft_strlen(ft_itoa(n)));
	}
	else if (ch == 'u')
	{
		un = va_arg(args, unsigned int);
		ft_putunbr_fd(un,1);
		return (ft_strlen(ft_itoa(n)));
	}
	else if (ch == 'x')
	{
		n = va_arg(args, int);
		ft_hexa(n);
		return (2);
	}
	else if (ch == 'X')
	{
		n = va_arg(args, int);
		ft_uphexa(n);
		return (2);
	}
	else if (ch == 'p')
	{
		p = va_arg(args, void *);
		ft_pointer(p);
		return (14);
	}
	else
		ft_putchar_fd('%',1);
	return (1);
}

int ft_printf(char *str, ...)
{
	int i;
	va_list args;
	int contagem;

	i = 0;
	contagem = 0;
	va_start(args,str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			contagem += print_n_cont(args,str[i+1]);
			i += 2;
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
	char *a = "nao deu";
	int i;

	i = ft_printf("%p\n",&a);
	ft_printf("%d\n",i);
	i = printf("%p\n",&a);
	printf("%d\n",i);
	return 0;

}*/
