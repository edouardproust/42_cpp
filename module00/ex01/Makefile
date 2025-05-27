NAME = phonebook
FLAGS = -Wall -Werror -Wextra -std=c++98
DEPFLAGS = -MMD -MP
SRC = main.cpp \
	PhoneBook.cpp \
	Contact.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $^ -o $@

$(OBJ_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ $(FLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY = all clean fclean re
