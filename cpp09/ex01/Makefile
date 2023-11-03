CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp RPN.cpp
HEAD =  RPN.hpp
NAME = RPN

all: $(NAME)

$(NAME): $(SRCS) $(HEAD)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all 

.PHONY: all clean fclean re
