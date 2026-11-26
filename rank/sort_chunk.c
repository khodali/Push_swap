/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:38:52 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/26 09:12:00 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_stack_list *a, t_stack_list *b,
	t_chunk chunk, t_operations *stats)
{
	int		i;
	int		len;
	t_stack	*node;

	len = size(a->head);
	i = 0;
	while (i < len && a->head != NULL)
	{
		node = a->head;
		if (node->rank >= chunk.start && node->rank <= chunk.end)
			pb(a, b, stats);
		else
			ra(a, stats);
		i++;
	}
}

void	sort_chunks(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	t_chunk	chunk;
	int		total_len;
	int		root;

	total_len = size(a->head);
	if (total_len < 2)
		return ;
	root = get_chunk_size(total_len);
	chunk.start = 0;
	chunk.end = root - 1;
	while (chunk.start < total_len)
	{
		push_chunk(a, b, chunk, stats);
		chunk.start = chunk.end + 1;
		chunk.end = chunk.end + root;
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
