/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:52:07 by macosta           #+#    #+#             */
/*   Updated: 2020/02/27 11:35:14 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[i] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (i);
		if (base[i] == base[j])
			return (i);
		j = i + 1;
		while (base[i] != base[j] && base[j] != '\0')
			j++;
		i++;
	}
	if (i == 1)
		return (1);
	return (j);
}

void	ft_rec(int nbr, char *base, int size)
{
	long nb;

	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= size)
		ft_rec((nb / size), base, size);
	if (nbr >= 0)
		ft_putchar(base[(nb % size)]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_base_check(base);
	if (size == 1)
		return ;
	ft_rec(nbr, base, size);
	return ;
}
