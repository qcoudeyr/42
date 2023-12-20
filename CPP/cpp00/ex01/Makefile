CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

HEADERS = PhoneBook.hpp
SRCS = PhoneBook.cpp
OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))

NAME = PhoneBook

all: $(OBJDIR) $(NAME)
	@echo "\033[32m\tCompilation done !\033[0m"

$(OBJDIR)%.o: %.cpp $(HEADERS)
	@$(CXX) $(CFLAGS) -I$(<D) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)  # Define 'megaphone' target
	@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
	@echo "\033[2m\033[31mStart to compile\033[0m"
	@mkdir -p $(OBJDIR)


clean:
	@echo "\033[2m\033[31mStart to CLEAN\033[0m"
	@rm -f $(OBJS)
	@echo "\033[32m\tCLEAN is done!\033[0m"

fclean: clean
	@clear
	@echo "\033[2m\033[31mStart to FCLEAN\033[0m"
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@echo "\033[32m\tFCLEAN is done!\033[0m"


re: fclean all

.PHONY: all clean fclean re
