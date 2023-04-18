CC = clang
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1000000

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
	rm -f $(NAME) $(OBJS)
	rm -f debug

re: fclean all

debug: CFLAGS += -g
debug: $(OBJS)
	clear
	$(CC) $(CFLAGS) -o debug $(OBJS)

sanitize: $(OBJS)
	$(CC) $(CFLAGS) -o debug $(OBJS) -g -fsanitize=address
	colour-valgrind --tool=memcheck --leak-check=full --track-origins=yes --error-exitcode=1 ./debug 2>&1

	./debug
.PHONY: all clean fclean re bonus debug
