# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++20
HDRS		:= -Iinclude

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= Base.cpp
SRC_MAIN	:= main.cpp

OBJS		:= $(OBJ_DIR)/Base.o
OBJS_MAIN	:= $(OBJ_DIR)/main.o 

# Program name
NAME		:= identify

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