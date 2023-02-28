CC = clang
CFLAGS = -Wall -Wextra -Werror

INCLUDE = ft_printf.h\
		./srcs/ft_split.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strlcpy.c \
		./srcs/ft_strrchr.c \
		./srcs/ft_strtrim.c \
		./srcs/ft_putstr_fd.c

SRCS =  ft_printf.c \

OBJS = $(SRCS:.c=.o) $(INCLUDE:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) debug

fclean: clean
	rm -f $(NAME) debug

re: fclean all

debug:
	$(CC) $(CFLAGS) $(SRCS) -I $(INCLUDE) -g -o debug

.PHONY: all clean fclean re bonus
