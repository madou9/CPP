# Compiler
CC := c++

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++98

# Executable name
NAME := easyfind

# Source files
SRCS := main.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Rule for generating executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule for generating object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS)

# Full clean target
fclean: clean
	rm -f $(NAME)

# Rebuild target
re: fclean all

# Phony targets
.PHONY: all clean fclean re

# # check that lnx
# docker images

# #if not lnx (in the directory where is the dockerfile)
# 	docker build -t . lnx
# # run the container
# docker run --rm -itv $PWD:/cpp lnx