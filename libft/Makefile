###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RESET=\033[0m
BLACK=\033[1;30m
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
WHITE=\033[1;37m
OBJS = \
	$(GNL_OBJS) \
	$(PRINTF_OBJS) \
	$(STRINGS_OBJS)
HEAD = ./
SRC_PATH = ./srcs/

all: $(NAME)

###############################################################################
#                                GET NEXT LINE                                #
###############################################################################
GNL_DIR = $(SRC_PATH)gnl/
GNL_FILES = \
		get_next_line.c
GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_FILES))
GNL_OBJS = $(GNL_SRCS:.c=.o)

$(GNL_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE GET_NEXT_LINE FUNCTION!!!$(RESET)"; \
	fi

gnl: $(GNL_OBJS)
	@ar rcs $(NAME) $(GNL_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)the get_next_line function $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

###############################################################################
#                                   PRINTF                                    #
###############################################################################
PRINTF_DIR = $(SRC_PATH)printf/
PRINTF_FILES = \
		address_print.c \
		char_print.c \
		ft_printf.c \
		hexa_print.c \
		num_print.c \
		str_print.c \
		unsigned_base_print.c
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

$(PRINTF_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE PRINTF FUNCTION!!!$(RESET)"; \
	fi

printf: $(PRINTF_OBJS)
	@ar rcs $(NAME) $(PRINTF_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)printf functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

###############################################################################
#                                  STRINGS                                    #
###############################################################################
STRINGS_DIR = $(SRC_PATH)strings/
STRINGS_FILES = \
		ft_split.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_substr.c
STRINGS_SRCS = $(addprefix $(STRINGS_DIR), $(STRINGS_FILES))
STRINGS_OBJS = $(STRINGS_SRCS:.c=.o)

$(STRINGS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE STRING FUNCTIONS!!!$(RESET)"; \
	fi

strings: $(STRINGS_OBJS)
	@ar rcs $(NAME) $(STRINGS_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)string functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

###############################################################################
#                                  COMPLETE                                   #
###############################################################################
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(BLUE)ARCHIVE $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)OBJECTS $(RED)DESTROYED$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)ARCHIVE $(RED)DESTROYED: $(CYAN)libft.a$(RESET)"

re: fclean all

.PHONY: all clean fclean re
