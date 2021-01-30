/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:01:32 by macosta           #+#    #+#             */
/*   Updated: 2020/02/06 15:17:07 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put2char(char c, char b)
{
	write(1, &c, 1);
	write(1, &b, 1);
}

void	ft_put_multi_char(char c, char b, char a)
{
	write(1, &c, 1);
	write(1, &b, 1);
	write(1, &a, 1);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0' - 1;
	while (++i <= '7')
	{
		j = i;
		while (++j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				if ((i < j) && (j < k))
				{
					ft_put_multi_char(i, j, k);
					if (i != '7')
					{
						ft_put2char(',', ' ');
					}
				}
				k++;
			}
		}
	}
}
