/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:03:35 by macosta           #+#    #+#             */
/*   Updated: 2020/06/25 10:03:53 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_count(const char *format)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (ft_isconv(format[i]) == 0)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

int				ft_isconv(char c)
{
	unsigned int	i;

	i = 0;
	while (CONV[i])
	{
		if (c == CONV[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_isflag(char c)
{
	unsigned int	i;

	i = 0;
	while (FLAG[i])
	{
		if (c == FLAG[i])
			return (1);
		i++;
	}
	return (0);
}
