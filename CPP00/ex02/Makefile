
CXX := c++

CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

NAME :=	Account

SRCS :=  Account.cpp tests.cpp

OBJS := $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean