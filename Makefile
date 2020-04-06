##
## EPITECH PROJECT, 2019
## lemin
## File description:
## Makefile
##

SRC = $(shell find . -name '*.c')

OUT = lem_in

CFLAGS =  -I./include -Wall -W

CFLAGS_DEBUG = -g3

CC = gcc

OBJ	=	$(SRC:.c=.o)

$(OUT): re

debug:	compile_debug

compile:	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)
	rm -f *.o

compile_debug:	CFLAGS += $(CFLAGS_DEBUG)

compile_debug:	fclean	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)

clean:
	$(shell find . -name '*.o' -delete)

fclean:	clean
	$(RM) -rf $(OUT)

re: fclean compile