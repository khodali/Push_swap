#include "push_swap.h"

void	swap(t_stack_list *stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *rest;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	rest = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	first->next = rest;
	if (rest)
		rest->prev = first;
	else
		stack->tail = first;
	stack->head = second;
}

void	sa(t_stack_list *a, t_operations *stats)
{
	if (!a || !a->head || !a->head->next || !stats)
		return ;
	swap(a);
	stats->sa++;
	stats->total_op++;
	if (!g_silent)
		write(1, "sa\n", 3);
}

void	sb(t_stack_list *b, t_operations *stats)
{
	if (!b || !b->head || !b->head->next || !stats)
		return ;
	swap(b);
	stats->sb++;
	stats->total_op++;
	if (!g_silent)
		write(1, "sb\n", 3);
}

void	ss(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (!a || !b || !stats)
		return ;
	if ((!a->head || !a->head->next) && (!b->head || !b->head->next))
		return ;
	swap(a);
	swap(b);
	stats->ss++;
	stats->total_op++;
	if (!g_silent)
		write(1, "ss\n", 3);
}
