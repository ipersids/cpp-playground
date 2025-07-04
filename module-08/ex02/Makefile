# Compilation variables
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++20 -MMD -MP
# -MMD generates dependency files (.d) that list all headers for source
# -MP adds phony targets for headers to prevent errors if headers are removed
HDRS		:= -I.

# Directories
OBJ_DIR		:= obj

# Sources and objects
SRCS		:= 
SRC_MAIN	:= main.cpp

OBJS		:= 
OBJS_MAIN	:= $(OBJ_DIR)/main.o

# Dependency files (for tracking header changes)
DEPS        := $(OBJS:.o=.d) $(OBJS_MAIN:.o=.d)

# Program name
NAME		:= exe_mutant_stack

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

# Include the auto-generated dependency information
-include $(DEPS)

.PHONY: all clean fclean re run