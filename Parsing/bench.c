/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 15:21:22 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/22 15:51:33 by mhatamle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    run_algorithms(t_bench *bench)
{
    simple_sort(&bench->simple_a, &bench->simple_b, &bench->simple_stats);
    sort_chunks(&bench->medium_a, &bench->medium_b, &bench->medium_stats);
    radix_sort(&bench->complex_a, &bench->complex_b, &bench->complex_stats);
}

int init_bench(t_bench *bench, t_stack_list *original)
{
    int success;

    *bench = (t_bench){0};
    bench->simple_a = clone_stack(original, &success);
    if (!success)
        return (0);
    bench->medium_a = clone_stack(original, &success);
    if (! success)
    {
        free_bench(bench);
        return (0);
    }
    bench->complex_a = clone_stack(original, &success);
    if (!success)
    {
        free_bench(bench);
        return (0);
    }
    return (1);
}

void    run_bench(t_stack_list *original)
{
    t_bench bench;
    
    if (!init_bench(&bench, original))
    {
        fprintf(stderr, "Error\n");
        return ;
    }
    run_algorithms(&bench);
    print_bench(&bench);
    free_bench(&bench);
}