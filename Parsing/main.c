/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:25:54 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/22 14:25:57 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	strcmp(const char *s1, const char *s2)
{
	size_t	i;

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


algorithm	check_flags (int argc, char **argv, int *start)
{
	algorithm strategy;

	strategy = ADAPTIVE;
	*start = 1;
	// we dont need this ig
	//	*error = 0;


	while (*start < argc  && argv[*start][0] == '-' && argv[*start][1] == '-')
	{
		if (strcmp(argv[*start], "--simple") == 0)
			strategy = SIMPLE;
		else if (strcmp(argv[*start], "--medium") == 0)
			strategy = MEDIUM;
		else if (strcmp(argv[*start], "--complex") == 0)
			strategy = COMPLEX;
		else if (strcmp(argv[*start], "--adaptive") == 0)
			strategy = ADAPTIVE;
		else if (strcmp(argv[*start], "--bench") == 0)
			strategy = BENCH;
		else
			return (INVALID);

		(*start)++;
	}
	return (strategy);
}

int	validate_args(int argc, char **argv, int start)
{
	
}

int	main(int argc, char **argv)
{
	t_algorithm		algo;
	int				i;
	int				*rank;
	char			**numbers;
	char			**args;
	t_stack_list	a;
	t_stack_list	b;
	t_operations		stats;

	// add the line decide whats the algo
	stats = {0};
	a.head = NULL;
	a.tail = NULL;
	b.head = NULL;
	b.tail = NULL;
	numbers = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (1);
		args = numbers;
	}
	else
		args = &argv[1];
	i = 0;
	while (args[i])
	{
		if (!validate_and_add(&a, args[i]))
		{
			free_split(numbers);
			free_stack(&a);
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	free_split(numbers);
	if (size(a.head) <= 1)
	{
		free_stack(&a);
		return (0);
	}
	rank = get_rank(a.head);
	if (!rank || !init_rank(&a, rank, size(a.head)))
	{
		free(rank);
		free_stack(&a);
		return (1);
	}
	free(rank);
	sort_chunks(&a, &b);
	sort_back_to_a(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
