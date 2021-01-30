/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:06:05 by macosta           #+#    #+#             */
/*   Updated: 2020/02/18 19:48:15 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	i = 0;
	if (min >= max)
		return ((int *)0);
	if (!(range = malloc(sizeof(range) * ((max - min)))))
		return ((int *)0);
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
