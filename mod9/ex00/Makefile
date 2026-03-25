# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 10:53:30 by cpollock          #+#    #+#              #
#    Updated: 2026/01/23 10:53:53 by cpollock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++
CFLAGS = -Wall -Wextra -Werror
CPPSTD = -std=c++98

SOURCES = main.cpp \
		  BitcoinExchange.cpp

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = BitcoinExchange.hpp

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
