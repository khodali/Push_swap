/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pirntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 22:44:15 by kalhouda          #+#    #+#             */
/*   Updated: 2026/11/27 22:44:47 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void printf_char(char c)
{
    write(2, &c, 1);
}

void printf_str(const char *str)
{
    int len;

    if (!str)
        return;
    len = 0;
    while (str[len])
        len++;
    write(2, str, len);
}

void printf_number(int number)
{
    if (number == -2147483648)
    {
        printf_str("-2147483648");
        return;
    }
    if (number < 0)
    {
        printf_char('-');
        number = -number;
    }
    if (number > 9)
        printf_number(number / 10);
    printf_char((number % 10) + '0');
}