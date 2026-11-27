/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:37 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/27 22:45:08 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stack(t_stack_list *stack)
{
	t_stack *current;
	t_stack *next;

	if (!stack)
		return;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
}
