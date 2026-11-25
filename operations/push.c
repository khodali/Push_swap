#include "push_swap.h"

void	push(t_stack_list *src, t_stack_list *dst)
{
	t_stack *tmp;

	if (!src || !src->head || !dst)
		return ;
	tmp = src->head;
	src->head = tmp->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	tmp->next = dst->head;
	tmp->prev = NULL;
	if (dst->head)
		dst->head->prev = tmp;
	else
		dst->tail = tmp;
	dst->head = tmp;
}

void	pb(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a || !b || !a->head || !stats)
		return ;
	push(a, b);
	stats->pb++;
	stats->total_op++;
	if (!g_silent)
		write(1, "pb\n", 3);
}

void	pa(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a || !b || !b->head || !stats)
		return ;
	push(b, a);
	stats->pa++;
	stats->total_op++;
	if (!g_silent)
		write(1, "pa\n", 3);
}
