/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:17:00 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/26 09:24:25 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(float disorder_value, const char *strategy,
		t_operations *stats)
{
	fprintf(stderr, "[bench] disorder: %.2f%%\n", disorder_value * 100.0f);
	fprintf(stderr, "[bench] strategy: %s\n", strategy);
	fprintf(stderr, "[bench] total_ops: %d\n", stats->total_op);
	fprintf(stderr, "[bench] sa: %d sb: %d ss: %d ", stats->sa, stats->sb,
		stats->ss);
	fprintf(stderr, "pa: %d pb: %d\n", stats->pa, stats->pb);
	fprintf(stderr, "[bench] ra: %d rb: %d rr: %d ", stats->ra, stats->rb,
		stats->rr);
	fprintf(stderr, "rra: %d rrb: %d rrr: %d\n", stats->rra, stats->rrb,
		stats->rrr);
}
