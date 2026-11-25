#include "push_swap.h"

void	rotate(t_stack_list *stack)
{
	t_stack *last;
	t_stack *first;
	t_stack *next;

	if (!stack || !stack->head || !stack->head->next || !stack->tail)
		return ;
	last = stack->tail;
	first = stack->head;
	next = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	next->prev = NULL;
	stack->head = next;
	stack->tail = first;
}

void	ra(t_stack_list *a, t_operations *stats)
{
	if (!a || !a->head || !a->head->next || !stats)
		return ;
	rotate(a);
	stats->ra++;
	stats->total_op++;
	if (!g_silent)
		write(1, "ra\n", 3);
}

void	rb(t_stack_list *b, t_operations *stats)
{
	if (!b || !b->head || !b->head->next || !stats)
		return ;
	rotate(b);
	stats->rb++;
	stats->total_op++;
	if (!g_silent)
		write(1, "rb\n", 3);
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
	if (!g_silent)
		write(1, "rr\n", 3);
}
