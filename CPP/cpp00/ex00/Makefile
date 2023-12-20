CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp
OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

NAME = megaphone

all: $(OBJDIR) $(NAME)
	@echo "\033[2m\033[31mStart to compile\033[0m"

$(OBJDIR)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(<D) -c $< -o $@
	@echo "\033[2m\033[31mCompilation done !\033[0m"

$(OBJDIR):
	@mkdir -p $(OBJDIR)


clean:
	@echo "\033[2m\033[31mStart to CLEAN\033[0m"
	@rm -f $(OBJS)
	@$(MAKE) -s -C ./libft clean
	@echo "\033[32m\tCLEAN is done!\033[0m"

fclean: clean
	@clear
	@echo "\033[2m\033[31mStart to FCLEAN\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -s -C ./libft fclean
	@rm -rf $(OBJDIR)
	@rm -rf ./utils/.env
	@rm -rf debug
	@echo "\033[32m\tFCLEAN is done!\033[0m"


re: fclean all

.PHONY: all clean fclean re
