NAME = push_swap
BONUS_NAME = checker

.PHONY : all mandatory bonus clean fclean re

all : $(NAME) $(BONUS_NAME)

$(NAME) : Makefile mandatory

$(BONUS_NAME) : Makefile bonus

mandatory :
	make -C ./mandatory

bonus :
	make -C ./bonus

clean : Makefile
	rm -f ./mandatory/*.o && rm -f ./bonus/*.o && make fclean -C ./libft

fclean : Makefile clean
	rm -f $(NAME) checker && rm -f bonus/checker mandatory/push_swap

re : Makefile fclean all
	