NAME     = philo
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -pthread

MODE     = none
ifeq ($(MODE), pretty)
	CFLAGS += -D DEBUG_FORMATTING=1
endif
ifeq ($(MODE), debug)
	CFLAGS += -D DEBUG_FORMATTING=1 -fsanitize=thread -g
endif

SRC_PATH = sources/
OBJ_PATH = objects/

SRC      = main.c \
           parsing.c \
           grim_reaper.c \
           time.c \
           philosopher.c \
           init.c \
           output.c \
           exit.c

OBJS     = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

INC      = -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean