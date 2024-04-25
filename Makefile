##
## EPITECH PROJECT, 2023
## B-CPE-101-MAR-1-1-myprintf-samy.chakrouni
## File description:
## Makefile
##

#SRC =   *.c
SRC =   $(wildcard *.c)
SRC +=	$(wildcard fonctions/*.c)

OBJ =   $(patsubst %.c, %.o, $(SRC))

NAME =   mysh

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $ *.o
		rm -f fonctions/*.o

fclean: clean
		rm -f $(NAME)

re: fclean all