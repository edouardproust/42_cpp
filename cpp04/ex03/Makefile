NAME = materia
FLAGS = -Werror -Wall -Wextra -std=c++98 -Wshadow
DEPFLAGS = -MMD -MP
SRCS = main.cpp \
	Character/Character.cpp \
	Materia/AMateria.cpp \
	Materia/Cure.cpp \
	Materia/Ice.cpp \
	Materia/MateriaSource.cpp
HEADERS = -I./Materia -I./Character
OBJ_DIR = _obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $^ -o $@

$(OBJ_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ -c $(FLAGS) $(DEPFLAGS) $(HEADERS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re