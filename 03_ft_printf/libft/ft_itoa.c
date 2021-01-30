/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:42:41 by macosta           #+#    #+#             */
/*   Updated: 2020/05/06 10:22:49 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 10)
	{
		n /= 10;
		count++;
	}
	if (n < 10)
		count++;
	return (count);
}

static void	ft_itoa_record(char *str, int n, int *ptr)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		str[*ptr] = '-';
		*ptr = (*ptr) + 1;
		nb = -n;
	}
	if (nb >= 10)
	{
		ft_itoa_record(str, nb / 10, ptr);
		ft_itoa_record(str, nb % 10, ptr);
	}
	if (nb < 10)
	{
		str[*ptr] = nb + '0';
		*ptr = (*ptr) + 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		*ptr;

	ptr = &i;
	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_itoa_count(n) + 1));
	if (str)
	{
		ft_itoa_record(str, n, ptr);
		str[i] = '\0';
	}
	return (str);
}
