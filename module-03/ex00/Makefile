# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 00:23:08 by ipersids          #+#    #+#              #
#    Updated: 2025/02/19 12:03:06 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror
HDRS		:= -I.

# Directories
OBJ_DIR		:= obj
SRC_DIR		:= module-03

# Sources and objects
SRCS		:= ClapTrap.cpp
SRC_MAIN	:= main.cpp

OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/$(OBJ_DIR)/%.o)
OBJS_MAIN	:= $(SRC_MAIN:$(SRC_DIR)/%.cpp=$(SRC_DIR)/$(OBJ_DIR)/%.o)

# Program name
NAME		:= exe_trap

# Rules
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(HDRS) -cpp $< -o $@

$(NAME): $(OBJS) $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJS_MAIN) $(HDRS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run