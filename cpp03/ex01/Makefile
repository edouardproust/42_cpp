NAME = scavTrap
FLAGS = -Werror -Wall -Wextra -std=c++98
DEPFLAGS = -MMD -MP
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ $(FLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	g++ $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re