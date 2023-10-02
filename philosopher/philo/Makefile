CC = gcc
CFLAGS = -Wall -Werror -Wextra -lpthread -g
THREADFLAG = -fsanitize=thread

HEADERS = philo.h
SRCS = philo.c utils.c
OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREADFLAG) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(THREADFLAG) -c $< -o $@

norme:
	norminette $(SRCS) $(HEADERS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(OBJS) $(BOBJS) $(BNAME)
	rm -f debug

re: fclean all

.PHONY: all clean fclean re debug bonus
