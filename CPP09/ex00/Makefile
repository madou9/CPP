# Compiler
CC := c++

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++98

# Executable name
NAME := btc

# Source files
SRCS := main.cpp BitcoinExchange.cpp

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