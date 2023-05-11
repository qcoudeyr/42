CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./libft -lft

HEADERS = push_swap.h libft.h
SRCS = push_swap.c ps_utils_1.c ps_utils_2.c ps_sort_1.c ps_sort_2.c ps_init.c ps_small_sort.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

norme:
	norminette $(SRCS) $(HEADERS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)
	rm -f debug

re: fclean all debug

DVAL = "266 6 163 108 104 168 381 402 3 451 427 460"
debug: $(OBJS)
	clear
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o debug
	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./debug $(DVAL) 2>&1
	./debug $(DVAL) | ./Other/checker_linux $(DVAL)

.PHONY: all clean fclean re debug
