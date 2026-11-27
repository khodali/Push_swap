/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:58:41 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/27 22:45:30 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_list clone_stack(t_stack_list *original, int *success)
{
	t_stack_list clone;
	t_stack *current;
	t_stack *new;

	clone.head = NULL;
	clone.tail = NULL;
	if (!original || !success)
		return (clone);
	*success = 0;
	current = original->head;
	while (current != NULL)
	{
		new = new_node(current->value);
		if (!new)
		{
			free_stack(&clone);
			return (clone);
		}
		new->rank = current->rank;
		add_node_back(&clone, new);
		current = current->next;
	}
	*success = 1;
	return (clone);
}
