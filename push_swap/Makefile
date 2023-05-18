CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./libft -lft

HEADERS = ./Ps_file/push_swap.h libft.h
SRCS = ./Ps_file/push_swap.c ./Ps_file/ps_exit.c ./Ps_file/ps_utils_1.c ./Ps_file/ps_utils_2.c ./Ps_file/ps_sort_1.c ./Ps_file/ps_sort_2.c ./Ps_file/ps_init.c ./Ps_file/ps_small_sort.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

BSRCS = ./Checker/checker.c ./Ps_file/ps_exit.c ./Ps_file/ps_utils_1.c ./Ps_file/ps_utils_2.c ./Ps_file/ps_sort_1.c ./Ps_file/ps_sort_2.c ./Ps_file/ps_init.c ./Ps_file/ps_small_sort.c
BOBJS = $(BSRCS:.c=.o)

BNAME = checker

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

bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LDFLAGS) -o $(BNAME)

comp:
	./$(NAME) $(DVAL) | ./$(BNAME) $(DVAL)
	./$(NAME) $(DVAL) | ./Other/checker_linux $(DVAL)

DVAL = "883 551 868 995 526 837 187 823 400 183 234 380 198 780 888 721 627 499 101 15 991 81 401 175 441 404 736 289 88 776 708 817 929 509 186 804 304 279 771 769 184 808 944 909 932 671 949 148 353 206 954 704 136 119 84 367 393 74 424 288 934 295 256 297 869 669 559 479 716 446 185 813 977 275 798 678 920 11 18 332 477 738 989 587 999 62 454 364 537 688 753 759 483 603 737 251 942 474 591 978"

debug: $(OBJS)
	clear
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o debug
	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./debug $(DVAL) 2>&1
	./debug $(DVAL) | ./Other/checker_linux $(DVAL)

bdebug: $(BOBJS)
	clear
	$(CC) $(CFLAGS) $(BOBJS) $(LDFLAGS) -o debug
	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./debug $(DVAL) 2>&1

.PHONY: all clean fclean re debug bonus
