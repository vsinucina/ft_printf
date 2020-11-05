.PHONY: all clean fclean re

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_NAME  = calc_double.c	\
	ch_transform.c			\
	ft_buffer.c				\
	ft_itoa_base.c			\
	ft_itoa_pf.c			\
	ft_ldtoa_pf.c			\
	ft_parse.c				\
	ft_printf.c				\
	ft_utoa_pf.c			\
	is_valid.c				\
	num_transform.c			\
	p_transform.c			\
	parse.c

LIBFT_SRC_NAME = ft_atoi.c	\
	ft_bzero.c				\
	ft_isdigit.c			\
	ft_isnegative.c			\
	ft_isspace.c			\
	ft_memalloc.c			\
	ft_memchr.c				\
	ft_memset.c				\
	ft_power.c				\
	ft_putchar.c			\
	ft_putchar_fd.c			\
	ft_putendl.c			\
	ft_putendl_fd.c			\
	ft_putnchar.c			\
	ft_putstr.c				\
	ft_putstr_fd.c			\
	ft_putstr_free.c		\
	ft_strcat.c				\
	ft_strchr.c				\
	ft_strcmp.c				\
	ft_strcpy.c				\
	ft_strdup.c				\
	ft_strlen.c				\
	ft_strncpy.c

INCLUDES_NAME = ft_printf.h

#ft_printf
SRC_DIR = ./srcs
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))

INCLUDES_DIR = ./includes
INCLUDES = $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_NAME))

#libft
LIBFT_DIR = ./libft
LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/,$(LIBFT_SRC_NAME))
LIBFT_OBJ_DIR = $(addprefix $(LIBFT_DIR)/,$(OBJ_DIR))
LIBFT_OBJS = $(addprefix $(LIBFT_OBJ_DIR)/,$(LIBFT_SRC_NAME:.c=.o))

#color
GREEN = \033[0;32m
RED = \033[0;31m
EOC = \033[m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)✓ Building $(NAME)$(EOC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

clean:
	/bin/rm -f $(OBJS)
#	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)✗ Deletion of object files$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)✗ Deletion of $(NAME)$(EOC)"

re: fclean all
