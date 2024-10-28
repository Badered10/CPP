CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

NAME = BraiiiiiiinnnzzzZ

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY : clean



