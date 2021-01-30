/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:03:28 by macosta           #+#    #+#             */
/*   Updated: 2020/02/07 02:20:01 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp[size];

	i = 0;
	while (size >= 0)
	{
		temp[i] = tab[size];
		size--;
		i++;
	}
	while (size < i)
	{
		tab[size] = temp[size];
		size++;
	}
}
