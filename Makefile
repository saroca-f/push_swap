NAME = push_swap.a
NAME2 = checker.a
ARCHIVE = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar rcs

SRCS = 	main.c \
		error_control.c \
		split.c \
		split_tools.c \
		stack.c \
		stack_set_utils.c \
		stack_set_utils2.c \
		stack_set.c \
		stack_set2.c \
		stack_order.c \
		stack_steps.c \
		stack_order_utils.c \
		stack_order_sorter.c \
		stack_order_plus.c \
		stack_order_plus_plus.c \

SRCS_BONUS = 	checker.c \
				error_control.c \
				split.c \
				split_tools.c \
				stack.c \
				stack_set_utils.c \
				stack_set_utils2.c \
				stack_set.c \
				stack_set2.c \
				stack_order.c \
				stack_steps.c \
				stack_order_utils.c \
				stack_order_sorter.c \
				stack_order_plus.c \
				stack_order_plus_plus.c \
				get_next_line.c \
				get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(ARCHIVE)

bonus: $(CHECKER)

$(ARCHIVE): $(NAME)
	$(CC) $< -o $(ARCHIVE)

$(CHECKER): $(NAME2)
	$(CC) $< -o $(CHECKER)

$(NAME) : $(OBJS)
	$(MAKE_LIB) $(NAME) $^

$(NAME2) : $(OBJS_BONUS)
	$(MAKE_LIB) $(NAME2) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(NAME) $(NAME2)

fclean: clean
	rm -f $(ARCHIVE) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re
