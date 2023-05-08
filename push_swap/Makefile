CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./libft -lft

HEADERS = push_swap.h libft.h
SRCS = push_swap.c ps_utils_1.c ps_utils_2.c ps_sort.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f debug

fclean: clean
	rm -f $(NAME) $(OBJS)
	rm -f debug

re: fclean all

debug: CFLAGS += -g
debug: $(OBJS)
	clear
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o debug
	colour-valgrind -s --tool=memcheck --leak-check=full --track-origins=yes --error-exitcode=1 ./debug "98 25 47 58 13 85 4 2 64" 2>&1

bonus:

.PHONY: all clean fclean re bonus debug
