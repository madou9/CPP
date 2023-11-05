NAME = Zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS = ${SRCS:.cpp=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re : fclean all

PHONY : clean fclean re all