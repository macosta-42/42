/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:46:26 by macosta           #+#    #+#             */
/*   Updated: 2021/05/31 15:45:32 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		negate;
	long	result;

	negate = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		negate = -1;
		str++;
	}
	else
	{
		negate = 1;
		if (*str == '+')
			str++;
	}
	while (ft_isdigit(*str))
		result = (result * 10) + (*str++ - '0');
	return (result * negate);
}
