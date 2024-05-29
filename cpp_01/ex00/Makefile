# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 17:23:09 by ixu               #+#    #+#              #
#    Updated: 2024/05/29 19:34:17 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := zombie

OBJS_DIR := objs/

SRCS = $(addsuffix .cpp, main Zombie newZombie randomChump)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

FLAGS := -Wall -Wextra -Werror -std=c++11

COMPILER := c++

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
