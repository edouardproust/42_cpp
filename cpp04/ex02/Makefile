NAME = animal
FLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow
DEPFLAGS = -MMD -MP
SRCS = main.cpp \
	AAnimal.cpp \
	Cat.cpp \
	Dog.cpp \
	Brain.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ -c $(FLAGS) $(DEPFLAGS) $< -o $@

$(NAME): $(OBJS)
	g++ $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re