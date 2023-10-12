CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
THREADFLAG = -fsanitize=thread

HEADERS = philo.h
SRCS = philo.c utils.c routine.c routine_function.c init.c dead.c
OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

norme:
	norminette $(SRCS) $(HEADERS)

debug: CFLAGS += -g
debug: THREADFLAG :=
debug: fclean debug_build

debug_build: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o debug
	clear
#	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1
	colour-valgrind -s --tool=helgrind \
	./debug 3 800 500 200 5
clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(OBJS) $(BOBJS) $(BNAME)
	rm -f debug

re: fclean all

.PHONY: all clean fclean re debug bonus
