# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 09:56:49 by ipersids          #+#    #+#              #
#    Updated: 2025/04/03 22:02:10 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++11
HDRS		:= -Iinclude

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			   RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
			   Intern.cpp
SRC_MAIN	:= main.cpp

OBJS		:= $(OBJ_DIR)/Bureaucrat.o $(OBJ_DIR)/AForm.o \
			   $(OBJ_DIR)/ShrubberyCreationForm.o \
			   $(OBJ_DIR)/RobotomyRequestForm.o \
			   $(OBJ_DIR)/PresidentialPardonForm.o \
			   $(OBJ_DIR)/Intern.o
OBJS_MAIN	:= $(OBJ_DIR)/main.o 

# Program name
NAME		:= exe_bureaucrat

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
	rm -f $(NAME) *_shrubbery

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run