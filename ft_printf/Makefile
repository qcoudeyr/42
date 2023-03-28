CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h
SRCS =  ft_printf.c ./srcs/ft_memset.c ./srcs/ft_pttostr.c ./srcs/ft_putnbru.c ./srcs/ft_putnbr_base.c ./srcs/ft_strlen.c ./srcs/ft_strdup.c ./srcs/ft_strlcpy.c ./srcs/ft_strrchr.c  ./srcs/ft_putstr_fd.c ./srcs/ft_putnbr_fd.c ./srcs/ft_putchar_fd.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS) $(HEADERS)
	ranlib $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
