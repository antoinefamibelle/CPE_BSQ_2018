##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

NAME 	=	bsq

SRC	=	src/bsq.c					\
		src/second_part.c				\
		src/third_part.c				\
		src/fourth.c					\
		src/five.c					\
		every_function/my_putstr.c			\
		every_function/my_put_nbr.c			\
		every_function/my_putchar.c			\
		every_function/my_strlen.c		

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra
CFLAGS 	+=	-I ./include

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)

debug:		CFLAGS += -g3
debug:		re

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
