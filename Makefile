##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## No file there , just an epitech header example .
## You can even have multiple lines if you want !
##
SRC    =	main.c	\
			my_rpg.c	\
			menu/game.c  \
			menu/button.c \
			menu/sprite.c	\
			menu/menu.c	\
			snow_map/snow_map.c	\
			snow_map/action_key.c	\
			snow_map/map_movement.c	\
			snow_map/start_game_menu.c	\
			snow_map/menu/handle_key.c	\
			snow_map/tools/time.c	\
			snow_map/tools/check_contact.c	\
			snow_map/destroy/display.c	\
			snow_map/destroy/destroy_snow.c	\
			snow_map/initialize/inizialize_snow_map.c	\
			snow_map/initialize/inizialize_game_menu.c	\


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
