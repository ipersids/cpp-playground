# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 18:40:56 by ipersids          #+#    #+#              #
#    Updated: 2025/03/21 00:22:45 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++11
HDRS		:= -I.

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= Fixed.cpp bsp.cpp Point.cpp
SRC_MAIN	:= main.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJS_MAIN	:= $(SRC_MAIN:%.cpp=$(OBJ_DIR)/%.o)

# Program name
NAME		:= exe_bsp

# Rules
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(HDRS) -c $< -o $@

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