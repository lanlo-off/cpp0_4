SRCS = main.cpp Bureaucrat.cpp

NAME = bureaucrat

HEADER = Bureaucrat.hpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

#OBJS = $(SRCS:.cpp=.o)

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#%.o: %.cpp $(HEADER)
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

#clean:
#	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re