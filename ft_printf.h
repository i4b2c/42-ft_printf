#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int ft_printf(char *s,...);
int print_n_cont(va_list args, char ch);
void	ft_pointer(void *);
char ft_ptr_hexa(int n);
char *ft_strcpy(char *s, char *c);
void ft_uphexa(int n);
void ft_hexa(int n);
void ft_putunbr_fd(unsigned int i, int fd);

#endif
