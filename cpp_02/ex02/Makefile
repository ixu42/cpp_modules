# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 16:25:21 by ixu               #+#    #+#              #
#    Updated: 2024/06/05 16:26:01 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./a.out

OBJS_DIR := objs/

SRCS = $(addsuffix .cpp, main Fixed)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

FLAGS := -Wall -Wextra -Werror -std=c++11

COMPILER := c++

# Color scheme
BRIGHT_YELLOW := \033[0;93m
YELLOW := \033[0;33m
COLOR_RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(COMPILER) -o $(NAME) $(OBJS)
	@echo "$(BRIGHT_YELLOW)Built $(NAME)$(COLOR_RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)Built object directory$(COLOR_RESET)"

$(OBJS_DIR)%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c $< -o $@
	@echo "$(YELLOW)Built $@$(COLOR_RESET)"

clean:
	@rm -fr $(OBJS_DIR)
	@echo "$(YELLOW)Removed object files$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Removed $(NAME)$(COLOR_RESET)"

re: fclean all
