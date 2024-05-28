# 42-ft_printf

## Description
The **42-ft_printf** project is a part of the 42 curriculum, which aims to recreate the standard C library function `printf`. This project helps students understand and implement functions that handle a variable number of arguments, deepening their knowledge of variadic functions and formatted output in C.

## Repository Structure
The repository includes the following key files and directories:

- **Makefile**: Script to compile the library.
- **ft_printf.h**: Header file containing function prototypes and necessary includes.
- **ft_printf.c**: Main implementation file for the `ft_printf` function.
- **ft_printf_utils1.c**: Utility functions used by `ft_printf`.
- **ft_printf_utils2.c**: Additional utility functions for `ft_printf`.
- **len.c**: Helper functions for length calculations.
- **libft/**: Directory containing the `libft` library used as a dependency.

## Functions Implemented
Some of the functions implemented in this project include:

- `ft_printf`
- `print_n_cont`
- `ft_pointer`
- `ft_ptr_hexa`
- `ft_strcpy`
- `ft_uphexa`
- `ft_hexa`
- `ft_putunbr_fd`
- `ft_lenhexa`
- `ptrlen`
- `ft_printstr`
- `ft_putchar_rint`
- `ft_uitoa`
- `ft_printuinumb`
- `ft_unumlen`
- `ft_printnumb`

## How to Use
To compile and use the `ft_printf` library, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/i4b2c/42-ft_printf.git
    cd 42-ft_printf
    ```

2. Compile the library using the Makefile:
    ```sh
    make
    ```

3. Include `ft_printf.h` in your C project and link the compiled library:
    ```c
    #include "ft_printf.h"
    ```

4. Compile your project with the `libftprintf.a` library:
    ```sh
    gcc -o my_program my_program.c -L. -lftprintf
    ```
