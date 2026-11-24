NAME = push_swap 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = libft/libft.a

SRCS =  adaptive.c disorder.c  merge_count.c merge.c size.c stats_adaptive.c push.c reverse_rotate.c rotate.c swap.c add_node.c atol.c bench.c clone_stack.c free_bench.c free_split.c free.c helper_validation.c main.c  print_bench.c validation.c radix.c init_stackand_rank.c  rank.c sort_back_to_a.c sort_chunk.c utilities_selection.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
