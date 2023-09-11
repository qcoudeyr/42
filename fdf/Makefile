CC = gcc
CFLAGS = -g

LDFLAGS = -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
HEADERS = fdf.h ./libft/libft.h
SRCS = fdf.c draw.c parsing.c lib.c map.c
OBJS = $(SRCS:.c=.o)
NAME = fdf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)
	rm -f debug

norme:
	norminette $(SRCS) $(HEADERS)

re: fclean all

debug: re
	clear
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o debug
	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./debug 42.fdf
