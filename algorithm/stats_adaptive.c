#include "push_swap.h"

t_operations	*get_adaptive_stats(t_bench *bench, float disorder_value,
	const char **strategy)
{
	(void)disorder_value;
	*strategy = "Adaptive / Radix";
	return (&bench->complex_stats);
}
