/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 09:13:06 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/26 09:14:57 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operations	*get_adaptive_stats(t_bench *bench, float disorder_value,
		const char **strategy)
{
	if (disorder_value < 0.2f)
	{
		*strategy = "Adaptive / O(n²)";
		return (&bench->simple_stats);
	}
	if (disorder_value < 0.5f)
	{
		*strategy = "Adaptive / O(n√n)";
		return (&bench->medium_stats);
	}
	*strategy = "Adaptive / O(n log n)";
	return (&bench->complex_stats);
}
