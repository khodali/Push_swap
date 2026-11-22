/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 09:41:17 by mhatamle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/11/22 10:39:22 by kalhouda         ###   ########.fr       */
=======
/*   Updated: 2026/11/22 12:35:13 by mhatamle         ###   ########.fr       */
>>>>>>> 793c0f9 (hi)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
static void	move_max_to_top(t_stack_list *b, int max_pos, int len,
		operations *stats)
=======
static void	move_max_to_top(t_stacl_list *b, int max_pos, int len,
		t_operations *stats)
>>>>>>> 793c0f9 (hi)
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

void	sort_back_to_a(t_stack_list *a, t_stack_list *b, operations *stats)
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
