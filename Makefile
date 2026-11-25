NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = libft/libft.a

SRCS = algorithm/adaptive.c algorithm/disorder.c algorithm/merge_count.c \
	algorithm/merge.c algorithm/size.c algorithm/stats_adaptive.c \
	operations/push.c operations/reverse_rotate.c operations/rotate.c \
	operations/swap.c Parsing/add_node.c Parsing/atol.c Parsing/bench.c \
	Parsing/clone_stack.c Parsing/free_bench.c Parsing/free_split.c \
	Parsing/free.c Parsing/helper_validation.c Parsing/main.c \
	Parsing/print_bench.c Parsing/validation.c radix/radix.c \
	rank/init_stackand_rank.c rank/rank.c rank/sort_back_to_a.c \
	rank/sort_chunk.c selection/simple_sort.c \
	selection/utilities_selection.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
