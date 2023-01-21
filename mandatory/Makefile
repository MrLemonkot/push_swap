NAME = push_swap
LIBFT = ../libft/libft.a
SRCS = atoi1.c atoi2.c main.c parsing1.c parsing2.c stacks1.c stacks2.c sorting.c small_sort.c \
operations1.c operations2.c operations3.c functions.c
OBJS = $(SRCS:%.c=%.o)
HEADER = ./push_swap.h
LIBHEADER = ../libft/libft.h
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) Makefile ../libft/Makefile
	cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) && cp $(NAME) ..

$(LIBFT) :
	make -C  ../libft

makelibft : 
	make -C ../libft

%.o : %.c $(HEADER) $(LIBHEADER) Makefile ../libft/Makefile
	cc $(FLAGS) -c $< -o $@

$(LIBHEADER) : makelibft

.PHONY : all clean fclean re libfclean makelibft
