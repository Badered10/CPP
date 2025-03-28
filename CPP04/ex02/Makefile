
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

NAME = AbstractAnimal

SRCS = main.cpp Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean :
	@rm -rf $(OBJS)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY : clean
