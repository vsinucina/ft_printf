cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes)

add_executable(ft_printf
        includes/ft_printf.h
        libft/includes/libft.h
        libft/srcs/ft_atoi.c
        libft/srcs/ft_bzero.c
        libft/srcs/ft_isdigit.c
        libft/srcs/ft_isnegative.c
        libft/srcs/ft_isspace.c
        libft/srcs/ft_memalloc.c
        libft/srcs/ft_memchr.c
        libft/srcs/ft_memset.c
        libft/srcs/ft_power.c
        libft/srcs/ft_putchar.c
        libft/srcs/ft_putchar_fd.c
        libft/srcs/ft_putendl.c
        libft/srcs/ft_putendl_fd.c
        libft/srcs/ft_putnchar.c
        libft/srcs/ft_putstr.c
        libft/srcs/ft_putstr_fd.c
        libft/srcs/ft_putstr_free.c
        libft/srcs/ft_strcat.c
        libft/srcs/ft_strchr.c
        libft/srcs/ft_strcmp.c
        libft/srcs/ft_strcpy.c
        libft/srcs/ft_strdup.c
        libft/srcs/ft_strlen.c
        libft/srcs/ft_strncpy.c
        libft/srcs/main.c
        srcs/calc_double.c
        srcs/ch_transform.c
        srcs/ft_buffer.c
        srcs/ft_itoa_base.c
        srcs/ft_itoa_pf.c
        srcs/ft_ldtoa_pf.c
        srcs/ft_parse.c
        srcs/ft_printf.c
        srcs/ft_utoa_pf.c
        srcs/is_valid.c
        srcs/num_transform.c
        srcs/p_transform.c
        srcs/parse.c libft/srcs/main.c)
