NAME = libft.a
NAME_TESTER = check

INCLUDES = include/
C_FLAGS =  -I$(INCLUDES) -Wall -Werror -Wextra -g3 -O3
CC = cc

SRC_DIR = srcs/
SRC_NAME =	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_memcmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(C_FLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)

%.o:%.c
	@$(CC) $(C_FLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;32m Executable" $(NAME) "created"

tester:
	@cc $(C_FLAGS) main.c $(NAME) -o $(NAME_TESTER)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_TESTER)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all

.PHONY: all tester clean fclean re