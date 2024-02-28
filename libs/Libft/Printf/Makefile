CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
DEPS = ft_printf.h
SRC = ft_printf.c ft_putchar_p.c ft_putnbr_fd.c ft_putstr_printf.c ft_strlen.c ft_putnbr_hexa.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $^
%.o: %.c $(DEPS)
	@$(CC) -c $< -o $@ $(CFLAGS)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
