CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1024 -I. -L. -lft
SRC = get_next_line.c get_next_line_utils.c get_next_line.h main.c libft.*
NAME = get_next_line

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

norm:
	norminette

debug:
	$(CC) $(CFLAGS) $(SRC) -g -o debug
