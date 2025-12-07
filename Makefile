NAME = cube3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = -Wall -Wextra -g
LIBS = -lreadline -lhistory
HEADERS = parsing/parsing.h

# Sources
SRC =
PARSING = parsing/parse.c \
          parsing/parse_utils.c\
          parsing/line_parsing.c\
		  parsing/colour_atoi.c\
		  parsing/validate_map.c\
		  parsing/get_metadata.c
EXECUTE =
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
		libft/free_arr.c
	

OBJ_DIR = objects/
TEST_OBJ_DIR = test_objects/

ALL_SRC = $(SRC) $(COMMANDS) $(PARSING) $(EXECUTE)
OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(ALL_SRC))
TEST_OBJ = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(ALL_SRC))
PARSING_OBJ = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(PARSING))
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

# Pattern rule for test objects (includes main_parsing.c too)
$(TEST_OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(TESTFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME) test pars

re: fclean all

.PHONY: all clean fclean re test parse
