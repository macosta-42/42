/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:57:53 by macosta           #+#    #+#             */
/*   Updated: 2020/02/27 14:58:30 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base_from);
int		ft_scndcheck(char *str, char *base_from, int i);
int		ft_get_nb(char c, char *str);
int		ft_check_base(char *base);

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_gotit(int nbr, char *base_to)
{
	int		size_nbr;
	long	nb;

	nb = nbr;
	size_nbr = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= ft_strlen(base_to);
		size_nbr++;
	}
	return (size_nbr);
}

char	*ft_putnbr_base(int nbr2, char *base_to)
{
	int				index;
	char			*convert;
	unsigned int	nb;
	unsigned int	size_base;

	size_base = ft_strlen(base_to);
	if (nbr2 < 0)
		nb = nbr2 * -1;
	else
		nb = nbr2;
	index = (nbr2 < 0) ? ft_gotit(nbr2, base_to) + 1 : ft_gotit(nbr2, base_to);
	if (!(convert = malloc(sizeof(*convert) * (index + 1))))
		return (NULL);
	convert[index] = '\0';
	while (index--)
	{
		convert[index] = base_to[nb % size_base];
		if (nb < size_base)
			convert[index] = base_to[nb];
		if (nbr2 < 0 && index == 0)
			convert[index] = '-';
		nb /= size_base;
	}
	return (convert);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (ft_check_base(base_from) == 0 || ft_check_base(base_to) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (!(nbr))
		return (NULL);
	return (ft_putnbr_base(nb, base_to));
}
