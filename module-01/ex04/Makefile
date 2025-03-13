# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 18:56:10 by ipersids          #+#    #+#              #
#    Updated: 2025/03/13 19:54:58 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++11
HDRS		:= -I.

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= replace.cpp
SRC_MAIN	:= main.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJS_MAIN	:= $(SRC_MAIN:%.cpp=$(OBJ_DIR)/%.o)

# Program name
NAME		:= exe_replace

# Rules
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(HDRS) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJS_MAIN) $(HDRS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR) *.replace

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run