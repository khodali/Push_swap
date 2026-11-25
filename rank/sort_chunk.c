#include "push_swap.h"

static void	push_chunk(t_stack_list *a, t_stack_list *b, int start,
	int end, t_operations *stats)
{
	int	wanted;
	int	pushed;
	int	scanned;
	int	len;
	int	mid;

	wanted = end - start + 1;
	len = size(a->head);
	pushed = 0;
	scanned = 0;
	mid = start + (end - start) / 2;
	while (pushed < wanted && scanned < len)
	{
		if (a->head->rank >= start && a->head->rank <= end)
		{
			pb(a, b, stats);
			pushed++;
			if (b->head->rank < mid && b->head->next)
				rb(b, stats);
		}
		else
			ra(a, stats);
		scanned++;
	}
}

void	sort_chunks(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	int root;
	int start;
	int end;
	int total_len;

	total_len = size(a->head);
	if (total_len < 2)
		return ;
	root = get_chunk_size(total_len);
	if (root < 1)
		root = 1;
	start = 0;
	while (start < total_len)
	{
		end = start + root - 1;
		if (end >= total_len)
			end = total_len - 1;
		push_chunk(a, b, start, end, stats);
		start = end + 1;
	}
	sort_back_to_a(a, b, stats);
}

int	find_max_rank(t_stack *b)
{
	int		max_rank;
	t_stack	*node;

	if (!b)
		return (-1);
	max_rank = b->rank;
	node = b->next;
	while (node)
	{
		if (node->rank > max_rank)
			max_rank = node->rank;
		node = node->next;
	}
	return (max_rank);
}

int	find_max_position(t_stack *b)
{
	t_stack	*node;
	int		i;
	int		max_rank;
	int		max_pos;

	if (!b)
		return (-1);
	max_rank = b->rank;
	max_pos = 0;
	node = b->next;
	i = 1;
	while (node)
	{
		if (node->rank > max_rank)
		{
			max_rank = node->rank;
			max_pos = i;
		}
		node = node->next;
		i++;
	}
	return (max_pos);
}
