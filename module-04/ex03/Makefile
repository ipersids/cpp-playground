# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 13:19:35 by ipersids          #+#    #+#              #
#    Updated: 2025/03/23 16:30:32 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++11
HDRS		:= -Iinclude

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
SRC_MAIN	:= main.cpp

OBJS		:= $(OBJ_DIR)/AMateria.o $(OBJ_DIR)/Ice.o $(OBJ_DIR)/Cure.o \
			   $(OBJ_DIR)/Character.o $(OBJ_DIR)/MateriaSource.o
OBJS_MAIN	:= $(OBJ_DIR)/main.o

# Program name
NAME		:= exe_materia

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