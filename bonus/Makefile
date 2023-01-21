
NAME = checker

FLAGS = -Wall -Wextra -Werror
DEFINE = -D
SIZE = 10

SRC = 	get_next_line.c\
		get_next_line_utils.c\

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(DEFINE) BUFFER_SIZE=$(SIZE) $(SRC)