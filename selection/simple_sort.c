#include "push_swap.h"

void	simple_sort(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	while (a->head)
	{
		rotate_min_to_top(a, stats);
		pb(a, b, stats);
	}
	while (b->head)
	{
		pa(a, b, stats);
	}
}
