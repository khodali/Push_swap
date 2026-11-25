#include "push_swap.h"

void	adaptive_sort(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (size(a->head) <= 5)
		simple_sort(a, b, stats);
	else
		radix_sort(a, b, stats);
}
