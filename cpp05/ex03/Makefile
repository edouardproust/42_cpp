NAME = bureaucrat
CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98
DEPFLAGS = -MMD -MP
SRCS = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) -c $(FLAGS) $(DEPFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

