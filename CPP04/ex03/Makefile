
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address -O1

NAME = Materia

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp Garbge.cpp Cleaner.cpp
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
