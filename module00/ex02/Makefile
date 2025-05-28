NAME = accounts
FLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP
SRCS = tests.cpp Account.cpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ -c $(FLAGS) $(DEPFLAGS) $< -o $@

$(NAME): $(OBJS)
	g++ $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean re

-include $(DEPS)

.PHONY: all clean fclean re