
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FragTrap

SRCS = main.cpp ClapTrap.cpp FragTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME) clean

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean :
	@rm -rf $(OBJS)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY : clean
