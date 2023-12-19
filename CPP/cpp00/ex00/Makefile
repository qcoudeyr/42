vpath %.c %.o %.h %.a ./libft ./parsing ./error ./main ./builtins ./utils ./object
VPATH = . : ./libft : ./parsing : ./error : ./main : ./builtins : ./utils
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIB_DIR = ./libft/
LIBS = -lft -lreadline -lncurses -lhistory

HEADERS = minishell.h

SRCS =	main.c \
		parsing.c error.c bultinexe.c ft_cd.c ft_echo.c \
		remove_quotes.c find_redirect.c heredoc.c signal.c\
		env_var.c pipe.c bonus.c utils.c free.c exec.c \
		error_2.c env.c ft_unset.c ft_export.c init.c \
		ft_pwd.c export_utils.c import_env.c path.c path2.c\
		utils2.c

OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

NAME = megaphone

all: $(OBJDIR) $(NAME)

$(OBJDIR)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(<D) -c $< -o $@

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
