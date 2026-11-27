/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:16:47 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/27 22:26:25 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int my_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_algorithm check_flags(int argc, char **argv, int *start, int *bench)
{
	t_algorithm strategy;

	strategy = ADAPTIVE;
	*start = 1;
	*bench = 0;
	while (*start < argc && argv[*start][0] == '-' && argv[*start][1] == '-')
	{
		if (my_strcmp(argv[*start], "--simple") == 0)
			strategy = SIMPLE;
		else if (my_strcmp(argv[*start], "--medium") == 0)
			strategy = MEDIUM;
		else if (my_strcmp(argv[*start], "--complex") == 0)
			strategy = COMPLEX;
		else if (my_strcmp(argv[*start], "--adaptive") == 0)
			strategy = ADAPTIVE;
		else if (my_strcmp(argv[*start], "--bench") == 0)
			*bench = 1;
		else
		{
			write(2, "Error\n", 6);
			return (INVALID);
		}
		(*start)++;
	}
	return (strategy);
}

int load_arguments(int count, char **args, int start, t_stack_list *a)
{
	while (start < count)
	{
		if (validate_and_add(a, args[start]) == -1)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			return (-1);
		}
		start++;
	}
	if (!a->head)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	else
		return (1);
}

int parse_arguments(int argc, char **argv, int start, t_stack_list *a)
{
	char **numbers;
	int count;
	int error;

	if (start >= argc)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (argc - start == 1)
	{
		numbers = ft_split(argv[start], ' ');
		if (!numbers)
			return (-1);
		count = 0;
		while (numbers[count])
			count++;
		error = load_arguments(count, numbers, 0, a);
		free_split(numbers);
		return (error);
	}
	// ./ps 1 2 3 return the numbers themselvess
	return (load_arguments(argc, argv, start, a));
}

void initialize_program(t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	*a = (t_stack_list){0};
	*b = (t_stack_list){0};
	*stats = (t_operations){0};
}

int initialize_input_and_return_bench(int argc, char **argv, t_stack_list *a, t_algorithm *strategy)
{
	int start;
	int bench;

	*strategy = check_flags(argc, argv, &start, &bench);
	if (*strategy == INVALID)
		return (-1);
	if (parse_arguments(argc, argv, start, a) == -1)
		return (-1);
	return (bench);
}

int initialize_ranks(t_stack_list *a)
{
	int *rank;
	int len;

	len = size(a->head);
	rank = get_rank(a->head);
	if (!rank)
		return (-1);
	if (!init_rank(a, rank, len))
	{
		free(rank);
		return (-1);
	}
	free(rank);
	return (1);
}

void execute_strategy(t_algorithm strategy, t_stack_list *a, t_stack_list *b, t_operations *stats)
{
	if (strategy == SIMPLE)
		simple_sort(a, b, stats);
	else if (strategy == MEDIUM)
		sort_chunks(a, b, stats);
	else if (strategy == COMPLEX)
		radix_sort(a, b, stats);
	else if (strategy == ADAPTIVE)
		adaptive_sort(a, b, stats);
}

int is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack_list a;
	t_stack_list b;
	t_algorithm strategy;
	t_operations stats;
	int bench;

	initialize_program(&a, &b, &stats);
	bench = initialize_input_and_return_bench(argc, argv, &a, &strategy);
	if (bench == -1 || initialize_ranks(&a) == -1)
	{
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	if (is_sorted(a.head) == -1)
		execute_strategy(strategy, &a, &b, &stats);
	return (0);
}
