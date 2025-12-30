NAME = cube3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = -Wall -Wextra -g -O3
LIBS = -lmlx -lXext -lX11 -lm
HEADERS = parsing/parsing.h

# Sources
SRC =
PARSING = parsing/parse.c \
          parsing/parse_utils.c\
          parsing/line_parsing.c\
		  parsing/colour_atoi.c\
		  parsing/validate_map.c\
		  parsing/get_metadata.c\
		  parsing/validate_texture.c
GAME_LOOP = game_loop/game_loop.c\
			raycasting/raycasting.c\
			game_loop/key_hooks.c\
			game_loop/utils.c\
			game_loop/player_movement.c


RENDER_TESTING = render_test/test.c $(GAME_LOOP)\
				render_test/tooling.c\
				render_test/draw_line.c\
				render_test/draw_minimap.c\
				render_test/draw_box.c\
				render_test/create_player2d.c\
				render_test/textures.c\
				render_test/get_wall_orientation.c


PROJECTION = projection/projection.c


LIBFT = libft/ft_strlen.c\
		libft/ft_isdigit.c\
		libft/fd_to_str_arr.c\
		libft/ft_append_str_arr.c\
		libft/get_next_line.c\
		libft/get_next_line_utils.c\
		libft/ft_split.c\
		libft/ft_strncmp.c\
		libft/ft_calloc.c\
		libft/ft_strtrim.c\
		libft/free_arr.c\
		libft/ft_strchr.c\
		libft/ft_memcpy.c\
		libft/get_nth_line.c
	

OBJ_DIR = objects/
TEST_OBJ_DIR = test_objects/

ALL_SRC = $(SRC) $(COMMANDS) $(PARSING) $(EXECUTE)
OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(ALL_SRC))
TEST_OBJ = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(ALL_SRC))
PARSING_OBJ = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(PARSING))
RENDER_TESTING_OBJ= $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(RENDER_TESTING))
GAME_LOOP_OBJ_TEST = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(GAME_LOOP))
PROJECTION_OBJ_TEST = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(PROJECTION))
LIBFT_OBJ = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(LIBFT))
MAIN_PARSING_OBJ = $(TEST_OBJ_DIR)parsing/main_parsing.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ---- TEST BUILD ----
test: $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o test

# Build parse test binary with libft and main_parsing
parse: $(PARSING_OBJ) $(LIBFT_OBJ) $(MAIN_PARSING_OBJ) 
	$(CC) $(TESTFLAGS) $^ -o pars
	./pars

rendert: $(RENDER_TESTING_OBJ) $(LIBFT_OBJ) $(PARSING_OBJ) $(GAME_LOOP_OBJ_TEST) $(PROJECTION_OBJ_TEST)
	$(CC) $(TESTFLAGS) $(LIBS) $^ -o rendt
	./rendt files/test1.cub

# Pattern rule for test objects (includes main_parsing.c too)
$(TEST_OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(TESTFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME) test pars rendt

re: fclean all

.PHONY: all clean fclean re test parse
