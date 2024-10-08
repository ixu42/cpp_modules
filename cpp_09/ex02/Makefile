# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 10:28:31 by ixu               #+#    #+#              #
#    Updated: 2024/09/12 12:55:55 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe

OBJS_DIR := objs/

SRCS = $(addsuffix .cpp, main PmergeMe)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

FLAGS := -Wall -Wextra -Werror -Wshadow -std=c++17
DEBUG_FLAGS := -DDEBUG_MODE=1

COMPILER := c++

# Color scheme
BRIGHT_YELLOW := \033[0;93m
YELLOW := \033[0;33m
COLOR_RESET := \033[0m

# Default target
all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(COMPILER) -o $(NAME) $(OBJS)
	@echo "$(BRIGHT_YELLOW)Built $(NAME)$(COLOR_RESET)"

# Debug target
debug: FLAGS += $(DEBUG_FLAGS)
debug: .debug

.debug: $(OBJS_DIR) $(OBJS)
	@$(COMPILER) -o $(NAME) $(OBJS)
	@echo "$(BRIGHT_YELLOW)Built $(NAME) (DEBUG_MODE)$(COLOR_RESET)"
	@touch .debug

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)Built object directory$(COLOR_RESET)"

$(OBJS_DIR)%.o: %.cpp .flags
	@$(COMPILER) $(FLAGS) -c $< -o $@
	@echo "$(YELLOW)Built $@$(COLOR_RESET)"

.flags: flags
	@echo 'FLAGS: $(FLAGS)' > .flags_current
	@cmp -s .flags_current $@ || mv -f .flags_current $@

clean:
	@rm -fr $(OBJS_DIR) .debug .flags .flags_current
	@echo "$(YELLOW)Removed object files$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Removed $(NAME)$(COLOR_RESET)"

re: fclean all

.PHONY: flags