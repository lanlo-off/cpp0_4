# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 13:23:34 by cpollock          #+#    #+#              #
#    Updated: 2026/01/28 13:23:49 by cpollock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror
CPPSTD = -std=c++98

SOURCES = main.cpp \
		  PmergeMe.cpp

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = PmergeMe.hpp

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
