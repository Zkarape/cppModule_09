NAME      = PmergeMe

CXX        = c++ 

CXXFLAGS     = -Wextra -Werror -Wall -g -ggdb3 -std=c++98 -pedantic -fsanitize=address# 

SRC_FILES = $(wildcard *.cpp)

OBJ_FILES = $(SRC_FILES:.cpp=.o)
HEADER = $(wildcard *.hpp)

%.o: %.cpp $(HEADER) Makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
		$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re