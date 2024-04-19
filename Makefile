##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## No file there , just an epitech header example .
## You can even have multiple lines if you want !
##
SRC    =	src/main.c	\
			src/game.c  \
			src/button.c \
			src/sprite.c	\


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
