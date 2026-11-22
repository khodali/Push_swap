/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhatamle <mhatamle@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:36:25 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/22 09:45:18 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(long number, int digit, long limit)
{
	if (number > (limit - digit) / 10)
		return (0);
	return (1);
}

int	get_sign(const char **str)
{
	int	sign;
	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	parse_digits(const char *str, long *number, long limit)
{
	int	digit;

	*number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		digit = *str - '0';
		if (!check_overflow(*number, digit, limit))
			return (0);
		*number = (*number * 10) + digit;
		str++;
	}
	return (1);
}

int	ft_atol(const char *str, long *result)
{
	int		sign;
	long	number;
	long	limit;

	if (!str || !result)
		return (0);
	sign = get_sign(&str);
	if (sign == -1)
		limit = 2147483648L;
	else
		limit = 2147483647L;
	if (*str < '0' || *str > '9')
		return (0);
	if (!parse_digits(str, &number, limit))
		return (0);
	*result = number * sign;
	return (1);
}
