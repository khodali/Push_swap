/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:17:00 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/24 14:17:02 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_simple_bench(t_operations *stats)
{
    fprintf(stderr,"SIMPLE: %d operations\n", stats->total_op);
}

void print_medium_bench(t_operations *stats)
{
    fprintf(stderr,"MEDIUM: %d operations\n", stats->total_op);
}

void print_complex_bench(t_operations *stats)
{
    fprintf(stderr,"COMPLEX: %d operations\n", stats->total_op);
}

void print_bench(t_bench *bench)
{
    print_simple_bench(&bench->simple_stats);
    print_medium_bench(&bench->medium_stats);
    print_complex_bench(&bench->complex_stats);
}