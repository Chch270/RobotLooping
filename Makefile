##
## EPITECH PROJECT, 2021
## CPOOL_2021_DAY03_STREAM
## File description:
## Makefile
##

SRC		=		main.c					\
				src/begin_game.c		\
				src/create_map.c		\
				src/game.c				\
				src/mouvements.c

OBJ		=		$(SRC:.c=.o)

NAME	=		robotLoop

CC		=		gcc

CPPFLAGS	=	-I ./include -l csfml-graphics -l csfml-window -l csfml-network -l csfml-system -l csfml-audio

CFLAGS		=	-Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all