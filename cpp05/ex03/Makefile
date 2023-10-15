CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
HEAD = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp
NAME = worker

all: $(NAME)

$(NAME): $(SRCS) $(HEAD)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
