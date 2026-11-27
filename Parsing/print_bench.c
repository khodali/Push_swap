/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:17:00 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/27 22:29:24 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_disorder(float disorder)
{
	int n;
	int decimal;

	n = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	printf_str("[bench] disorder: ");
	printf_number(n);
	printf_char('.');
	if (decimal < 10)
		printf_char('0');
	printf_number(decimal);
	printf_str("%\n");
}

static void print_basic_ops(t_operations *stats)
{
	printf_str("[bench] sa: ");
	printf_number(stats->sa);
	printf_str(" sb: ");
	printf_number(stats->sb);
	printf_str(" ss: ");
	printf_number(stats->ss);
	printf_str(" pa: ");
	printf_number(stats->pa);
	printf_str(" pb: ");
	printf_number(stats->pb);
	printf_char('\n');
}

static void print_rotate_ops(t_operations *stats)
{
	printf_str("[bench] ra: ");
	printf_number(stats->ra);
	printf_str(" rb: ");
	printf_number(stats->rb);
	printf_str(" rr: ");
	printf_number(stats->rr);
	printf_str(" rra: ");
	printf_number(stats->rra);
	printf_str(" rrb: ");
	printf_number(stats->rrb);
	printf_str(" rrr: ");
	printf_number(stats->rrr);
	printf_char('\n');
}

static void print_strategy(const char *strategy)
{
	printf_str("[bench] strategy: ");
	printf_str(strategy);
	printf_char('\n');
}

void print_bench(float disorder_value, const char *strategy, t_operations *stats)
{
	if (!stats || !strategy)
		return;
	print_disorder(disorder_value);
	print_strategy(strategy);
	printf_str("[bench] total_ops: ");
	printf_number(stats->total_op);
	printf_char('\n');
	print_basic_ops(stats);
	print_rotate_ops(stats);
}