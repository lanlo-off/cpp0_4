SRC_DIR = src
HEADER_DIR = includes
OBJ_DIR = obj

SRCS = main.cpp Base.cpp functions.cpp
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME = identifier

HEADER = Base.hpp
HEADER := $(addprefix $(HEADER_DIR)/, $(HEADER))

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re