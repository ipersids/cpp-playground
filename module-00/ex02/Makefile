# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++11

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= Account.cpp tests.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Program name
NAME		:= exe_account

# Rules
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run