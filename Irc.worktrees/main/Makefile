vpath ./objs ./srcs
VPATH = . : ./objs : ./srcs

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = Main.hpp Authentication.hpp  Channel.hpp  Command.hpp  File.hpp  Logger.hpp  Main.hpp  Permissions.hpp  Server.hpp  User.hpp

SRCS =	Main.cpp Authentication.cpp  Channel.cpp  Command.cpp  File.cpp  Logger.cpp Permissions.cpp  Server.cpp  User.cpp

OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))

NAME = ircserv

all: $(OBJDIR) $(NAME)
	@echo "\033[32m\tCompilation done !\033[0m"

$(NAME): $(OBJS)
	@echo "\033[2m\033[31mStart to make $(NAME)\033[0m"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m\t$(NAME) is done !\033[0m"

$(OBJDIR)%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -I$(<D) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "\033[2m\033[31mStart to CLEAN\033[0m"
	@rm -f $(OBJS) *.log
	@echo "\033[32m\tCLEAN is done!\033[0m"

fclean: clean
	@clear
	@echo "\033[2m\033[31mStart to FCLEAN\033[0m"
	@rm -f $(NAME) *.log
	@rm -rf $(OBJDIR)
	@rm -rf debug
	@echo "\033[32m\tFCLEAN is done!\033[0m"


re: fclean all

debug: CXXFLAGS += -g
debug: re
	@clear
	@$(CXX) $(CXXFLAGS) -g $(OBJS) -o debug


val: debug
	valgrind -s --track-origins=yes --tool=memcheck --show-leak-kinds=all --leak-check=full --error-exitcode=1 \
	./debug 6667 1234

.PHONY: all clean fclean re debug norme
