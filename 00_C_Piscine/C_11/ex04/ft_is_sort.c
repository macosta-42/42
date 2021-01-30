/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:23:44 by macosta           #+#    #+#             */
/*   Updated: 2020/02/26 18:20:17 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int mon;

	mon = 0;
	while (length > 1)
	{
		if (f(tab[length - 2], tab[length - 1]) > 0)
		{
			if (mon == 1)
				return (0);
			mon = -1;
		}
		if (f(tab[length - 2], tab[length - 1]) < 0)
		{
			if (mon == -1)
				return (0);
			mon = 1;
		}
		length--;
	}
	return (1);
}
