
CC = c++

CPPGLAGS = -Wall -Wextra -Werror

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = Account

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CPPGLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean :clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean