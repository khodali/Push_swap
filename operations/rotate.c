/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:09:25 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/27 22:39:27 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_stack_list *stack)
{
	t_stack *last;
	t_stack *tmp;
	t_stack *first_next;

	if (!stack || !stack->head || !stack->head->next || !stack->tail)
		return;
	last = stack->tail;
	tmp = stack->head;
	first_next = tmp->next;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	first_next->prev = NULL;
	stack->head = first_next;
	stack->tail = tmp;
}

void ra(t_stack_list *a, t_operations *stats)
{
	if (!a || !a->head || !a->head->next || !stats)
		return;
	rotate(a);
	stats->ra++;
	stats->total_op++;
	write(1, "ra\n", 3);
}

void rb(t_stack_list *b, t_operations *stats)
{
	if (!b || !b->head || !b->head->next || !stats)
		return;
	rotate(b);
	stats->rb++;
	stats->total_op++;
	write(1, "rb\n", 3);
}

void rr(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a || !b || !stats)
		return;
	if (!a->head || !a->head->next)
		return;
	if (!b->head || !b->head->next)
		return;
	rotate(a);
	rotate(b);
	stats->rr++;
	stats->total_op++;
	write(1, "rr\n", 3);
}
