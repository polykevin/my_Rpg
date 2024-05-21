##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##
SRC    =	src/main.c					\
			src/game.c  				\
			src/button.c 				\
			src/sprite.c				\
			src/menu.c					\
			src/map_movement.c	        \
			src/start_game_menu.c	    \
			src/time.c	                \
			src/check_contact.c	        \
			src/display.c	            \
			src/player_movement.c       \
			src/utils.c 				\


OBJ =   	$(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra

CPPFLAGS = -I ./include/

LDFLAGS = -L ./lib/my/

LDLIBS = -lm -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME = 		rpg

MAKE = make

all:		$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my/
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

debug: CFLAGS += -g3

debug: re

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/my/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/my/ fclean

re: fclean all
