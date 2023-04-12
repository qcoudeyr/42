CC = clang
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

HEADERS = get_next_line.h
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)

NAME = get_next_line

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f debug

re: fclean all

debug: CFLAGS += -g
debug: $(OBJS)
	$(CC) $(CFLAGS) -o debug $(OBJS)
	clear
	colour-valgrind -s --tool=memcheck --leak-check=full --track-origins=yes --error-exitcode=1 ./debug 2>&1


.PHONY: all clean fclean re bonus debug
