vpath %.c %.o %.h %.a ./libft ./free ./parsing ./error ./main ./map ./utils ./object ./mlx_linux ./rendering ./windows
VPATH = . : ./libft : ./parsing : ./error : ./main : ./utils : ./map : ./rendering : ./mlx_linux : ./windows : ./free
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIB_DIR = ./libft/
LIBS = -lft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

HEADERS = cub3d.h

SRCS =	main.c

OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

NAME = cub3D

all: $(OBJDIR) $(NAME) norme

$(NAME): $(OBJS) libft
	@echo "\033[2m\033[31mStart to make $(NAME)\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) $(LIBS) -o $(NAME)
	@echo "\033[32m\t$(NAME) is done !\033[0m"

$(OBJDIR)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(<D) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

libft:
	@echo "\033[2m\033[31mCooking the LIBFT\033[0m"
	@$(MAKE) -s -C ./libft
	@echo "\033[32m\tLIBFT is done!\033[0m"

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

NORME = ./libft ./free ./parsing ./error ./main ./map ./utils ./object ./rendering ./windows

norme:
	@echo "\033[2m\033[31mLet's check the norme for $(NAME)\033[0m"
	@if [ $$(norminette $(NORME) $(HEADERS) | grep Error | wc -c) -eq 0 ]; then \
		echo "\033[32m\033[1m\tNorme is OK!\033[0m"; \
	else \
		echo "\033[31m\033[1m\tNorme is BAD!\033[0m"; \
		norminette $(NORME) $(HEADERS) | grep Error ;\
		echo "\033[31m\033[1mNEED TO FIX ALL OF THIS !!!\033[0m"; \
	fi

debug: $(OBJS)
	@clear
	@$(CC) $(CFLAGS) -g $(OBJS) -L$(LIB_DIR) $(LIBS) -o debug
	valgrind -s --track-origins=yes --tool=memcheck --leak-check=full --error-exitcode=1 \
	./debug

.PHONY: all clean fclean re debug libft norme

#--show-leak-kinds=all --track-origins=yes
