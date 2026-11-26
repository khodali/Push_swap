/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:09:25 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/26 09:17:13 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_list *stack)
{
	t_stack	*last;
	t_stack	*tmp;
	t_stack	*first_next;

	if (!stack || !stack->head || !stack->head->next || !stack->tail)
		return ;
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

void	ra(t_stack_list *a, t_operations *stats)
{
	if (!a || !a->head || !a->head->next || !stats)
		return ;
	rotate(a);
	stats->ra++;
	stats->total_op++;
}

void	rb(t_stack_list *b, t_operations *stats)
{
	if (!b || !b->head || !b->head->next || !stats)
		return ;
	rotate(b);
	stats->rb++;
	stats->total_op++;
}

void	rr(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a || !b || !stats)
		return ;
	if ((!a->head || !a->head->next) && (!b->head || !b->head->next))
		return ;
	rotate(a);
	rotate(b);
	stats->rr++;
	stats->total_op++;
}
