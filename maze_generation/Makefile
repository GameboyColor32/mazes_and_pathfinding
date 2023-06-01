##
## EPITECH PROJECT, 2020
## dante makefile
## File description:
## makefile
##

NAME	=	dante

SRC	=	src/main.c	\
		src/maze.c	\
		src/stack.c	\
		src/vector.c	\
		src/node.c	\
		src/utils.c	\
		src/vec.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-g -Wall -Wextra -W -I./include

# LDFLAGS	=	-L./lib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
