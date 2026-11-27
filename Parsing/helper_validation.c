/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:17:10 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/27 22:44:58 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool is_valid_syntax(char *str)
{
	if (!str || !*str)
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

bool is_within_int_range(char *str)
{
	long num;

	if (!ft_atol(str, &num))
		return (false);
	return (true);
}
