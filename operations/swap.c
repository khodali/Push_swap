/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:45:34 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/22 14:57:21 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_list *stack)
{
	t_stack	*next_current;
	t_stack	*head;
	t_stack	*last;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	head = stack->head;
	next_current = head->next;
	last = next_current->next;
	next_current->next = head;
	next_current->prev = NULL;
	head->prev = next_current;
	head->next = last;
	if (last)
		last->prev = head;
	else
		stack->tail = head;
	stack->head = next_current;
}

void	sa(t_stack_list *a, t_operations *stats)
{
	if (!a || !(a)->head || !a->head->next || !stats)
		return ;
	stats->sa++;
	stats->total_op++;
	swap(a);
}

void	sb(t_stack_list *b, t_operations *stats)
{
	if (!b || !b->head || !b->head->next || !stats)
		return ;
	stats->sb++;
	stats->total_op++;
	swap(b);
}

void	ss(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a | !b | !stats)
		return;
	if ((!a->head || !a->head->next) && (!b->head || !b->head->next))
		return;
	stats->ss++;
	stats->total_op++;
	swap(a);
	swap(b);
}
