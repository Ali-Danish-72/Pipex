###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RESET=\033[0m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[1;34m
CYAN=\033[1;36m
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
HEADERS = ./
SRCS_DIR = ./sources/
SRCS =	parent.c child.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIR = ./objects/
OBJS = $(SRCS:%.c=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_PATH)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(LIBFT)  -o $(NAME)
	@echo "$(BLUE)PROGRAM $(GREEN)CREATED: $(CYAN)pipex$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_PATH): $(SRCS_PATH)
	@make -s $(OBJS)

$(OBJS):
	@$(CC) $(CFLAGS) -c -I $(HEADERS) $(SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

clean:
	@make -s -C $(LIBFT_DIR) fclean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)PROGRAM $(RED)DESTROYED: $(CYAN)pipex.$(RESET)"

re: fclean all

.PHONY: all clean fclean re