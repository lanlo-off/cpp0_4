SRCS = main.cpp harl.cpp

NAME = harl

#HEADER = harl.hpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all