# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 17:28:21 by ixu               #+#    #+#              #
#    Updated: 2024/05/30 12:20:05 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := account

OBJS_DIR := objs/

SRCS = $(addsuffix .cpp, Account tests)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

FLAGS := -Wall -Wextra -Werror -std=c++98

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
