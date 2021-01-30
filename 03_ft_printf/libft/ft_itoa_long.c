/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:06:39 by macosta           #+#    #+#             */
/*   Updated: 2020/06/12 18:06:56 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len(long nb)
{
	size_t	neg;

	neg = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		neg = 1;
	}
	if (nb / 10 == 0)
		return (1 + neg);
	else
		nb = nb / 10;
	return (1 + neg + ft_len(nb));
}

char				*ft_itoa_us(unsigned int n)
{
	char			*s;
	unsigned int	i;
	size_t			len;
	long			nb;

	nb = n;
	len = ft_len(nb);
	if (!(s = (char *)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		s[0] = '-';
	}
	if (nb == 0)
		s[len - 1] = '0';
	i = -1;
	while (++i < len && nb > 0)
	{
		s[len - 1 - i] = nb % 10 + 48;
		nb = nb / 10;
	}
	s[len] = '\0';
	return (s);
}
