##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## No file there, just an epitech header example .
## You can even have multiple lines if you want !
##

SRC    =    my_getnbr.c		\
			my_revstr.c		\
			my_strcat.c		\
			my_str_isprintable.c	\
			my_strncpy.c	\
			my_isneg.c		\
			my_showmem.c	\
			my_strcmp.c		\
			my_str_isupper.c	\
			my_strstr.c		\
			my_is_prime.c	\
			my_showstr.c	\
			my_strcpy.c		\
			my_strlen.c		\
			my_str_to_word_array.c	\
			my_compute_power_rec.c	\
			my_putchar.c	\
			my_show_word_array.c 	\
			my_str_isalpha.c	\
			my_strlowcase.c		\
			my_strupcase.c		\
			my_compute_square_root.c	\
			my_put_nbr.c	\
			my_sort_int_array.c		\
			my_str_islower.c		\
			my_strncat.c		\
			my_swap.c	\
			my_find_prime_sup.c		\
			my_putstr.c		\
			my_strcapitalize.c		\
			my_str_isnum.c		\
			my_strncmp.c	\
			my_printf.c	\
			fonctions.c	\
			fonctions2.c \
			put_p.c	\
			put_u.c \
			put_x.c \
			my_str_add.c	\
			my_int_to_str.c

OBJ =   	$(SRC:.c=.o)

NAME = 		libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
