NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -lhistory
HEADERS = minishell.h libft/libft.h\
		parsing/parsing.h commands/commands.h ids/ids.h execution/execution.h

SRC =
COMMANDS =
PARSING =
EXECUTE =

OBJ_DIR = objects/
TEST_OBJ_DIR = test_objects/

ALL_SRC = $(SRC) $(COMMANDS) $(PARSING) $(EXECUTE)
OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(ALL_SRC))
TEST_OBJ = $(patsubst %.c,$(TEST_OBJ_DIR)%.o,$(ALL_SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ---- TEST BUILD ----
test: $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o test

testj :
	make test -j `nproc`

sta:
	cc -g star/*.c libft/*.c -o sta
	


$(TEST_OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -Wall -Wextra -g -c $< -o $@

runt: test
	valgrind --leak-check=full --trace-children=yes --track-fds=all --show-leak-kinds=all --suppressions=readline.supp ./test

runtj:
	make fclean
	make test -j`nproc`
	make runt

ctest: all
	./minishell

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test runt ctest testj sta
