# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:00:10 by ixu               #+#    #+#              #
#    Updated: 2024/05/23 10:26:47 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

SRCS := megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS := -Wall -Wextra -Werror -std=c++11

COMPILER := g++

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) 

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
