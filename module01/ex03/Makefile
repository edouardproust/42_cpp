NAME = violence
FLAGS = -Werror -Wall -Wextra -std=c++98
DEPFLAGS = -MMD -MP
SRCS = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ $(FLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	g++ $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean all
