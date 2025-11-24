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

pretty:
	$(MAKE) MODE=pretty

debug:
	$(MAKE) MODE=debug

help:
	@printf "\nUsage:\n"
	@printf "  make           -> build default mode (no debug formatting)\n"
	@printf "  make pretty    -> build with debug-friendly colored output\n"
	@printf "  make debug     -> build with thread sanitizer support and debug flags\n"
	@printf "  make clean     -> remove objects\n"
	@printf "  make fclean    -> remove objects and binary\n\n"
	@printf "Example of build and run:\n"
	@printf "  make pretty && ./philo 5 800 200 200 3\n\n"

.PHONY: all re clean fclean pretty debug help
