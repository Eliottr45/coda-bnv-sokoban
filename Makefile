NAME = sokoban

SRCS = main.c \
	grille.c \
	box.c \
	player.c \
	arrive.c

all : $(NAME)

$(NAME) : $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re : fclean all