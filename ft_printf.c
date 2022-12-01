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

int ft_lenhexa(unsigned int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

int	ft_hexa(unsigned int n)
{
	int i;

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
			ft_putchar_fd(n + '0',1);
		else
			ft_putchar_fd(n + 'a' - 10,1);
	}
	return (i);
}

int	ft_uphexa(unsigned int n)
{
	int i;

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
			ft_putchar_fd(n + 'A' - 10,1);
	}
	return (i);

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

int	ptrlen(void *p)
{
	int i;
	uintptr_t c;

	c = (uintptr_t)p;
	i = 0;
	while(c / 16 != 0)
	{
		c = c / 16;
		i++;
	}
	return (++i);
}


int	ft_pointer(void * p)
{
	uintptr_t c;
	char *s;
	int i;
	int len;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)",1);
		return (5);
	}
	i = ptrlen(p);
	len = i;
	s = malloc(sizeof(int) * i + 1);
	c = (uintptr_t)p;
	s[i] = '\0';
	i--;
	while(i >= 0)
	{
		s[i] = ft_ptr_hexa(c % 16);
		c = c / 16;
		i--;
	}
	ft_putstr_fd("0x",1);
	ft_putstr_fd(s,1);
	free(s);
	return (len + 2);
}

int	ft_printnumb(int n)
{
	char *str;
	int len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str,1);
	free(str);
	return (len);
}

int	ft_unumlen(unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char *ft_uitoa(unsigned int n)
{
	char *str;
	int len;

	len = ft_unumlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while(n != 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_printuinumb(unsigned int n)
{
	char *str;
	int len;

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
	int i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)",1);
		return (6);
	}
	while(s[i] != '\0')
	{
		ft_putchar_fd(s[i],1);
		i++;
	}
	return (i);
}

int ft_putchar_rint(int i)
{
	ft_putchar_fd(i,1);
	return (1);
}

int	print_n_cont(va_list args, char ch)
{
	int i;

	i = 0;
	if(ch == 'c')
		i += ft_putchar_rint(va_arg(args, int));
	else if (ch == 's')
		i += ft_printstr(va_arg(args,char *));
	else if (ch == 'i' || ch == 'd')
		i += ft_printnumb(va_arg(args,int));	
	else if (ch == 'u')
		i += ft_printuinumb(va_arg(args,int));
	else if (ch == 'x')
		i += ft_hexa(va_arg(args,unsigned int));
	else if (ch == 'X')
		i += ft_uphexa(va_arg(args,unsigned int));
	else if (ch == 'p')
		i += ft_pointer(va_arg(args, void *));
	else if (ch == '%')
		i += ft_putchar_rint('%');
	else
		return (0);
	return (i);
}

int ft_printf(const char *str, ...)
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
	int i;

	i = ft_printf("%%%p\n",(void *)0);
	ft_printf("%d\n",i);
	i = printf("%%%p\n",(void *)0);
	printf("%d\n",i);
	return 0;

}*/
