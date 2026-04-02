# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/01 18:37:16 by ldubois           #+#    #+#              #
#    Updated: 2026/03/16 20:04:11 by ldubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+= --output-sync=target
SHELL		:= /bin/bash
NAME		= PmergeMe

CXX			= c++
LDFLAGS		=
CPPFLAGS	= -Iinclude

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP						\
			  -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast		\
			  -Wnon-virtual-dtor -Woverloaded-virtual -Wcast-align			\
			  -Wcast-qual -Wpointer-arith -Wpedantic -Wundef				\
			  -Wdouble-promotion -Wswitch-enum -Wswitch-default				\
			  -Wreorder -fdiagnostics-color=always -O3 -march=native

DEBUG_FLAGS	= -O0 -g3 -fno-omit-frame-pointer -DDEBUG
ASAN_FLAGS	= -fsanitize=address,undefined
TSAN_FLAGS	= -fsanitize=thread

HDRS		= include/PmergeMe.hpp			\
			  include/PmergeMe.tpp

SRCS		= src/main.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	@echo -n -e "\x1b[38;2;147;181;198mLinking executable \x1b[38;2;181;198;207m$@\x1b[0m "
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $^
	@echo -e "\x1b[1;32m✓\x1b[0m"

%.o: %.cpp
	@echo -n -e "\x1b[38;2;147;181;198mCompiling \x1b[38;2;181;198;207;3m$<\x1b[0m "
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	@echo -e "\x1b[1;32m✓\x1b[0m"

-include $(OBJS:.o=.d)

debug:
	@$(MAKE) --no-print-directory											\
		CXXFLAGS="$(filter-out -O%,$(CXXFLAGS)) $(DEBUG_FLAGS) $(ASAN_FLAGS)"	\
		LDFLAGS="$(LDFLAGS) $(ASAN_FLAGS)"									\
		re

tsan:
	@$(MAKE) --no-print-directory											\
		CXXFLAGS="$(filter-out -O%,$(CXXFLAGS)) $(DEBUG_FLAGS) $(TSAN_FLAGS)"	\
		LDFLAGS="$(LDFLAGS) $(TSAN_FLAGS)"									\
		re

check:
	@cppcheck --enable=all --inconclusive --quiet						\
		--language=c++ --std=c++03 --platform=unix64					\
		--suppress=missingIncludeSystem									\
		--suppress=checkersReport										\
		--check-level=exhaustive										\
		$(CPPFLAGS) $(SRCS)

scan:
	@scan-build --use-c++=clang++ $(MAKE) clean all

lint:
	@for f in $(SRCS); do 												\
		clang-tidy $$f -header-filter=.* -- $(CPPFLAGS) -std=c++98;		\
	done

format-check:
	@clang-format --dry-run --Werror $(SRCS) $(HDRS)

format:
	@clang-format -i $(SRCS) $(HDRS)

clean:
	@echo -n -e "\x1b[38;2;147;181;198mCleaning \x1b[0m"
	@$(RM) $(OBJS) $(OBJS:.o=.d)
	@echo -e "\x1b[1;32m✓\x1b[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all debug tsan check scan lint format-check format clean fclean re
