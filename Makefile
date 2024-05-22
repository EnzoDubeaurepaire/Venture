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
		src/utils/create_sprite.c \
		src/settings_screen/settings_overlay.c \
		src/settings_screen/settings_buttons.c \
		src/map_screen/init_map_screen.c \
		src/map_screen/map_screen.c \
		src/map_screen/map_renderer.c	\
		linked_list/list1.c \
		linked_list/list2.c \
		linked_list/list3.c \
		src/dialogue/init_struct_dialogue.c	\
		src/dialogue/dialogue.c	\
		src/dialogue/event_dialogue.c	\
		src/collision/collision.c	\
		src/stats/init_stats.c \
		src/stats/stats_renderer.c \
		src/utils/get_mouse_pos.c \

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window
LDFLAGS	+=	-lcsfml-network -lcsfml-audio -lm
CFLAGS	=	-Wall -Wextra -I./include
CFLAGS	+=	-Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
FAST	=	-Ofast -march=native -fno-builtin

NAME	=	my_rpg

all:		best

tests_run:
		echo "No Tests"

$(NAME):	$(OBJ)
		gcc $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

fast:		$(SRC)
		gcc $(CFLAGS) $(LDFLAGS) -o $(NAME) $(SRC) $(FAST)

debug:		$(OBJ)
		gcc $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) -g3

debug-fast:		$(SRC)
		gcc $(CFLAGS) $(LDFLAGS) -o $(NAME) $(SRC) $(FAST) -g3

best:		fclean $(SRC)
		@make --no-print-directory -j debug
		@make --no-print-directory clean

clean:
		rm -f $(OBJ) *.gcda *.gcno

fclean:		clean
		rm -f $(NAME) unit_tests

re:		fclean $(NAME)
