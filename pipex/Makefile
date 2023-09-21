CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./libft -lft

HEADERS = pipex.h
SRCS = pipex.c
OBJS = $(SRCS:.c=.o)

NAME = pipex

BSRCS = pipex.c
BOBJS = $(BSRCS:.c=.o)

BNAME = pipex

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

	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./debug infile "ls -l" "wc -l" outfile


launch: $(OBJS)
	clear
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o pipex
	clear
	./pipex infile "ls -l" "wc -l" outfile

bonus: $(BNAME)


.PHONY: all clean fclean re debug bonus
