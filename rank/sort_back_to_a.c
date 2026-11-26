/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 08:58:11 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/26 09:12:28 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_max_to_top(t_stack_list *b, int max_pos,
	int len, t_operations *stats)
{
	int	i;

	if (max_pos <= len / 2)
	{
		i = 0;
		while (i < max_pos)
		{
			rb(b, stats);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len - max_pos)
		{
			rrb(b, stats);
			i++;
		}
	}
}

void	sort_back_to_a(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	int	max_pos;
	int	len;

	while (b->head != NULL)
	{
		len = size(b->head);
		max_pos = find_max_position(b->head);
		move_max_to_top(b, max_pos, len, stats);
		pa(a, b, stats);
	}
}
