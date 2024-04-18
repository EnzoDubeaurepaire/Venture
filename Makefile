##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/launch_screen/launch_screen.c \
		src/game_struct/init_game_struct.c \
		src/game_struct/free_game_struct.c \
		src/event/event.c \
		src/menu/menu.c \
		src/menu/buttons_state.c \

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window
LDFLAGS	+=	-lcsfml-network -lcsfml-audio -lm
CFLAGS	=	-Wall -Wextra -I./include
CFLAGS	+=	-Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
FAST	=	-g3 -Ofast -march=native -fno-builtin

NAME	=	my_rpg

all:		fast

tests_run:
		echo "No Tests"

fast:		$(SRC)
		gcc -o $(NAME) $(SRC) $(FAST) $(CFLAGS) $(LDFLAGS)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re: 		fclean all
