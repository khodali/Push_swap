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
    simple_sort(&bench,
}

void   init_bench(t_bench *bench, t_stack_list *original)
{
    *bench = (t_bench){0};
    bench->simple_a = clone_stack(original);
    bench->medium_a = clone_stack(original);
    bench->complex_a = clone_stack(original);
}

void    run_bench(t_stack_list *original)
{
    t_bench bench;
    
    init_bench(&bench, original);
}