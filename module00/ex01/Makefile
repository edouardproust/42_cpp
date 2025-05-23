NAME = phonebook
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = PhoneBook.cpp Contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $^ -o $@

%.o: %.cpp Makefile
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
