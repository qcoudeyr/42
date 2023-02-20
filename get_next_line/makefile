CC = clang
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=n
SRC = get_next_line.c get_next_line_utils.c
INC = get_next_line.h
NAME = get_next_line

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -I $(INC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
