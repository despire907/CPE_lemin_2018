CC	= gcc -g

RM	= rm -f

NAME	= lem_in

SRC	=   /resolve/resolve.c  \
        /resolve/resolve_bis_one.c  \
        /resolve/resolve_bis_two.c  \
        constructeur.c  \
        constructeur_bis.c  \
        destructeur.c   \
        display.c   \
        fs_open_file.c  \
        load_files_in_mem.c \
        main.c  \
        my_strlen.c \
        fs_open_file.c \
        load_files_in_mem.c \


OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
