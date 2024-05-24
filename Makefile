##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##
SRC    =	src/main.c										\
			src/game/game.c									\
			src/button.c 									\
			src/sprite.c									\
			src/menu.c										\
			src/map/action_key.c							\
			src/map/map_movement.c							\
			src/map/player_movement.c						\
			src/map/snow_map.c								\
			src/map/tools/time.c							\
			src/map/tools/check_contact.c					\
			src/map/destroy/display.c						\
			src/map/destroy/destroy_snow.c					\
			src/map/inizialize/inizialize_snow_map.c		\
			src/map/inizialize/default_game.c				\
			src/inventory/inizialize/inizialize_game_menu.c	\
			src/inventory/handle_key.c						\
			src/inventory/print_inventory.c					\
			src/inventory/start_game_menu.c					\
			src/utils.c 									\
			src/interact.c 									\
			src/fight/fight.c								\
			src/fight/fight_animation.c 					\
			src/fight/update_fight.c 						\
			src/fight/fight_init.c 							\
			src/game/game_update.c 							\
			src/game/game_render.c 							\
			src/map_elements.c								\
			src/button_menu.c 								\
			src/fight/stats.c	\
			src/quete.c


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
