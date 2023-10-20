CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp ScalarConverter.cpp
HEAD =  ScalarConverter.hpp
NAME = Converter

all: $(NAME)

$(NAME): $(SRCS) $(HEAD)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
