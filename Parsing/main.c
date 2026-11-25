#include "push_swap.h"

int g_silent = 0;

static int my_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static t_algorithm check_flags(int argc, char **argv, int *start, int *bench)
{
	t_algorithm strategy;

	strategy = ADAPTIVE;
	*start = 1;
	*bench = 0;
	while (*start < argc && argv[*start][0] == '-'
		&& argv[*start][1] == '-')
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
			return (INVALID);
		(*start)++;
	}
	return (strategy);
}

static int is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void run_strategy(t_algorithm strategy, t_stack_list *a,
	t_stack_list *b, t_operations *stats)
{
	if (strategy == SIMPLE)
		simple_sort(a, b, stats);
	else if (strategy == MEDIUM)
		sort_chunks(a, b, stats);
	else if (strategy == COMPLEX)
		radix_sort(a, b, stats);
	else
		adaptive_sort(a, b, stats);
}

int main(int argc, char **argv)
{
	t_stack_list a;
	t_stack_list b;
	t_operations stats;
	t_algorithm strategy;
	int start;
	int bench;
	int *ranks;

	a = (t_stack_list){0};
	b = (t_stack_list){0};
	stats = (t_operations){0};
	strategy = check_flags(argc, argv, &start, &bench);
	if (strategy == INVALID || parse_arguments(argc, argv, start, &a) < 0)
	{
		if (strategy == INVALID)
			write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	if (is_sorted(a.head))
	{
		free_stack(&a);
		return (0);
	}
	ranks = get_rank(a.head);
	if (!ranks || !init_rank(&a, ranks, size(a.head)))
	{
		free(ranks);
		free_stack(&a);
		return (1);
	}
	free(ranks);
	if (bench)
	{
		g_silent = 1;
		run_bench(&a);
		g_silent = 0;
	}
	run_strategy(strategy, &a, &b, &stats);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
