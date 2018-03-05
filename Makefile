##
## EPITECH PROJECT, 2018
## philosophers
## File description:
## Created by martin.januario@epitech.eu
##

SRC	=	src/main.c				\
		src/parsing/parsing.c

OBJ	=	$(SRC:.c=.o)

NAME	=	philo

CFLAGS	=	-W -Wall -Wextra -I include/

LDFLAGS =	-Llib -lriceferee -lpthread

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

debug:		CFLAGS += -ggdb3

debug:		re

.PHONY:		all clean fclean re
