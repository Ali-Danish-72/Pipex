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
	$(CHECKERS_OBJS) \
	$(CONVERTERS_OBJS) \
	$(GNL_OBJS) \
	$(LISTS_OBJS) \
	$(MEMORY_OBJS) \
	$(PRINTF_OBJS) \
	$(PUT_FD_OBJS) \
	$(STRINGS_OBJS)
HEAD = ./
SRC_PATH = ./srcs/

all: $(NAME)

###############################################################################
#                                  CHECKERS                                   #
###############################################################################
CHECKERS_DIR = $(SRC_PATH)checkers/
CHECKERS_FILES = \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c
CHECKERS_SRCS = $(addprefix $(CHECKERS_DIR), $(CHECKERS_FILES))
CHECKERS_OBJS = $(CHECKERS_SRCS:.c=.o)

$(CHECKERS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE CHECKER FUNCTIONS!!!$(RESET)"; \
	fi

checkers: $(CHECKERS_OBJS)
	@ar rcs $(NAME) $(CHECKERS_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)checkers functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

###############################################################################
#                                  CONVERTERS                                 #
###############################################################################
CONVERTERS_DIR = $(SRC_PATH)converters/
CONVERTERS_FILES = \
		ft_absolute.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_tolower.c \
		ft_toupper.c
CONVERTERS_SRCS = $(addprefix $(CONVERTERS_DIR), $(CONVERTERS_FILES))
CONVERTERS_OBJS = $(CONVERTERS_SRCS:.c=.o)

$(CONVERTERS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE CONVERTERS FUNCTIONS!!!$(RESET)"; \
	fi

converters: $(CONVERTERS_OBJS)
	@ar rcs $(NAME) $(CONVERTERS_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)converters functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

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
#                                   LISTS                                     #
###############################################################################
LISTS_DIR = $(SRC_PATH)lists/
LISTS_FILES = \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c
LISTS_SRCS = $(addprefix $(LISTS_DIR), $(LISTS_FILES))
LISTS_OBJS = $(LISTS_SRCS:.c=.o)

$(LISTS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE LIST FUNCTIONS!!!$(RESET)"; \
	fi

lists: $(LISTS_OBJS)
	@ar rcs $(NAME) $(LISTS_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)list functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

###############################################################################
#                                   MEMORY                                    #
###############################################################################
MEMORY_DIR = $(SRC_PATH)memory/
MEMORY_FILES = \
		ft_bzero.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c
MEMORY_SRCS = $(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
MEMORY_OBJS = $(MEMORY_SRCS:.c=.o)

$(MEMORY_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE MEMORY FUNCTIONS!!!$(RESET)"; \
	fi

memory: $(MEMORY_OBJS)
	@ar rcs $(NAME) $(MEMORY_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)memory functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

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
#                                   PUT_FD                                    #
###############################################################################
PUT_FD_DIR = $(SRC_PATH)put_fd/
PUT_FD_FILES = \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_base_fd.c \
		ft_putstr_fd.c
PUT_FD_SRCS = $(addprefix $(PUT_FD_DIR), $(PUT_FD_FILES))
PUT_FD_OBJS = $(PUT_FD_SRCS:.c=.o)

$(PUT_FD_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE PUT_FD FUNCTIONS!!!$(RESET)"; \
	fi

put_fd: $(PUT_FD_OBJS)
	@ar rcs $(NAME) $(PUT_FD_OBJS)
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)put_fd functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

###############################################################################
#                                  STRINGS                                    #
###############################################################################
STRINGS_DIR = $(SRC_PATH)strings/
STRINGS_FILES = \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
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
	@echo "$(BLUE)ARCHIVE$(RESET) with $(MAGENTA)all functions $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)OBJECTS $(RED)DESTROYED$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)ARCHIVE $(RED)DESTROYED: $(CYAN)libft.a$(RESET)"

re: fclean all

.PHONY: all clean fclean re
