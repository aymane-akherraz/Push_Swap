NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_split.c helper.c list_helper.c operations2.c operations.c stack_funcs.c helper2.c list_helper2.c operations3.c push_swap.c sort_funcs.c validation_functs.c
BSRC = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c operations_bonus.c operations2_bonus.c operations3_bonus.c ft_split.c helper.c list_helper.c list_helper2.c stack_funcs.c validation_functs.c
OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

bonus: $(BONUS)

$(BONUS): $(BOBJ)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY:  all clean fclean re bonus
