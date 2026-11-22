/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:00:09 by mhatamle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/11/22 10:20:40 by kalhouda         ###   ########.fr       */
=======
/*   Updated: 2026/11/22 12:36:49 by mhatamle         ###   ########.fr       */
>>>>>>> 793c0f9 (hi)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_syntax(char *str)
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

bool	is_within_int_range(char *str)
{
	long	num;

	if (!ft_atol(str, &num))
		return (false);
	return (true);
}
