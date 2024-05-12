CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -Wshadow -Wno-shadow

HEADERS = Bureaucrat.hpp Aform.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
SRCS = main.cpp Bureaucrat.cpp Aform.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))

NAME = Intern

all: $(OBJDIR) $(NAME)
	@echo "\033[32m\tCompilation done !\033[0m"

$(OBJDIR)%.o: %.cpp $(HEADERS)
	@$(CXX) $(CFLAGS) -I$(<D) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
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
