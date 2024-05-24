##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/inventory/init_inventory.c	\
		src/inventory/show_inventory.c	\
		src/inventory/pick_up_item.c	\
		src/launch_screen/launch_screen.c \
		src/game_struct/init_game_struct.c \
		src/game_struct/free_game_struct.c \
		src/event/event.c \
		src/menu/menu.c \
		src/menu/buttons_state.c \
		src/utils/create_sprite.c \
		src/settings_screen/settings_overlay.c \
		src/settings_screen/settings_buttons_screen.c \
		src/settings_screen/settings_buttons.c \
		src/map_screen/init_map_screen.c \
		src/map_screen/map_screen.c \
		src/map_screen/map_renderer.c	\
		src/map_screen/switch_map.c	\
		src/map_screen/display_object.c	\
		src/dialogue/init_struct_dialogue.c	\
		src/dialogue/dialogue.c	\
		src/dialogue/event_dialogue.c	\
		src/collision/collision.c	\
		src/collision/collision_event.c	\
		src/collision/message.c	\
		src/stats/init_stats.c \
		src/stats/stats_renderer.c \
		src/utils/get_mouse_pos.c \
		src/pause_screen/buttons_state.c \
		src/pause_screen/pause.c \
		src/utils/exit_game.c \
		src/dialogue/destroyer.c \
		src/launch_screen/destroyer.c \
		src/map_screen/destroyer.c \
		src/menu/destroyer.c \
		src/pause_screen/destroyer.c \
		src/settings_screen/destroyer.c \
		src/stats/destroyer.c \
		src/save/save.c \
		src/save/check_save_elements.c \
		src/music/music.c \
		src/music/destroyer.c \
		src/music/init_music.c \
		src/utils/check_env.c \
		src/utils/check_assets.c \
		src/stats/get_stats.c \
		src/stats/set_stats.c \
		src/map_screen/health_bar.c \

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window
LDFLAGS	+=	-lcsfml-network -lcsfml-audio -lm
CFLAGS	=	-Wall -Wextra -I./include -g
CFLAGS	+=	-Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
FAST	=	-Ofast -march=native -fno-builtin

NAME	=	my_rpg

all:		$(NAME)

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
