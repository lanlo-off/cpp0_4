# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:13:03 by cpollock          #+#    #+#              #
#    Updated: 2026/01/27 16:13:15 by cpollock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++
CFLAGS = -Wall -Wextra -Werror
CPPSTD = -std=c++98

SOURCES = main.cpp \
		  RPN.cpp

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = RPN.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(CPPSTD) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(CPPSTD) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
