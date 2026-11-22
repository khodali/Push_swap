/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stackand_rank.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:22:31 by mhatamle          #+#    #+#             */
/*   Updated: 2026/11/22 13:05:05 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack_list *a, int argc, char **argv)
{
	int		i;
	int		value;
	t_stack	*node;

	i = 1;
	while (argc > i)
	{
		value = ft_atoi(argv[i]);
		node = new_node(value);
		if (node == NULL)
			return ;
		add_node_back(a, node);
		i++;
	}
}

// we have to convert this to int 

int	init_rank(t_stack_list *a, int *rank, int len)
{
	t_stack	*node;
	int		i;

	if (size(a->head) != len)
		return (0);
	node = a->head;
	i = 0;
	while (node != NULL)
	{
		node->rank = rank[i];
		node = node->next;
		i++;
	}
	return (1);
}
