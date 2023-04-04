CC = clang
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

HEADERS = get_next_line.h
SRCS = get_next_line.c get_next_line_utils.c
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
debug: $(OBJS) main.o
	$(CC) $(CFLAGS) main.o -o debug $(OBJS)
	clear
	colour-valgrind --tool=memcheck --leak-check=full --track-origins=yes --error-exitcode=1 ./debug 2>&1

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: all clean fclean re bonus debug
