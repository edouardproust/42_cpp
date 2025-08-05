NAME = mutant_stack
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp
HEADERS = MutantStack.hpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

$(OBJS_DIR)/%.o: %.cpp $(HEADERS) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean fclean re
