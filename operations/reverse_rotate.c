/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:18:07 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/16 09:43:59 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_list *stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !stack->head || !stack->head->next || !stack->tail)
		return ;
	head = stack->head;
	last = stack->tail;
	before_last = last->prev;
	last->next = head;
	last->prev = NULL;
	head->prev = last;
	before_last->next = NULL;
	stack->head = last;
	stack->tail = before_last;
}

void	rra(t_stack_list *a, t_operations *stats)
{
	if (!a || !a->head || !a->head->next || !stats)
		return ;
	reverse_rotate(a);
	stats->rra++;
	stats->total_op++;
}

void	rrb(t_stack_list *b, t_operations *stats)
{
	if (!b || !b->head || !b->head->next || !stats)
		return ;
	reverse_rotate(b);
	stats->rrb++;
	stats->total_op++;
}

void	rrr(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a || !b || !stats)
		return ;
	if ((!a->head || !a->head->next) && (!b->head || !b->head->next))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	stats->rrr++;
	stats->total_op++;
}
