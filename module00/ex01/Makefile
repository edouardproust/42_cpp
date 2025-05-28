NAME = phonebook
FLAGS = -Wall -Werror -Wextra -std=c++98
DEPFLAGS = -MMD -MP
SRCS = main.cpp \
	PhoneBook.cpp \
	Contact.cpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $^ -o $@

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	g++ $(FLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY = all clean fclean re
