/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:07:59 by macosta           #+#    #+#             */
/*   Updated: 2020/02/17 09:29:34 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		nb = 0;
	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if ((nb % 2) == 0)
		return (0);
	if (nb == 2147483647)
		return (1);
	while (i * i < nb)
	{
		i++;
		if ((nb % i) == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	next_prime = nb;
	while (ft_is_prime(next_prime) != 1)
		next_prime++;
	return (next_prime);
}
