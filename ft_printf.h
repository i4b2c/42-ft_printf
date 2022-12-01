#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int ft_printf(const char *s,...);
int print_n_cont(va_list args, char ch);
int	ft_pointer(void *);
char ft_ptr_hexa(int n);
char *ft_strcpy(char *s, char *c);
int ft_uphexa(unsigned int n);
int ft_hexa(unsigned int n);
void ft_putunbr_fd(unsigned int i, int fd);

#endif
