SRCS = main.cpp Zombie.cpp zombieHorde.cpp

NAME = horde

#HEADER = Zombie.hpp

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