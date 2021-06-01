/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:11:59 by macosta           #+#    #+#             */
/*   Updated: 2021/05/31 16:35:39 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ternary(int test, void *a, void *b)
{
	if (test)
		return (a);
	else
		return (b);
}

int	ft_ternary_i(int test, int a, int b)
{
	return (ft_ternary_l(test, a, b));
}

long	ft_ternary_l(int test, long a, long b)
{
	return (ft_ternary_ul(test, a, b));
}

unsigned long	ft_ternary_ul(int test, unsigned long a, unsigned long b)
{
	return ((unsigned long)ft_ternary(test, (void *)a, (void *)b));
}

double	ft_ternary_d(int test, double a, double b)
{
	if (test)
		return (a);
	else
		return (b);
}
