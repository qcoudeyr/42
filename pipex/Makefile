CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./libft -lft

HEADERS = pipex.h
SRCS = pipex.c parsing.c utils.c
OBJS = $(SRCS:.c=.o)

NAME = pipex

BSRCS = bonus.c parsing.c utils.c
BOBJS = $(BSRCS:.c=.o)

BNAME = bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

norme:
	norminette $(SRCS) $(HEADERS)
clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(OBJS) $(BOBJS) $(BNAME)
	rm -f debug

re: fclean all

debug: $(OBJS)
	clear
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o debug

	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 \
	./debug "pipex.c" "echo" "wc -l" "output"

#./debug "input" "grep Hello" "awk '{count++} END {print count}'" "output"

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LDFLAGS) -o $(BNAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: all clean fclean re debug bonus
