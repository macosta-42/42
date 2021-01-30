/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:29:54 by macosta           #+#    #+#             */
/*   Updated: 2020/02/06 16:08:46 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put2char(char a, char b)
{
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_coma(char nb1, char nb2)
{
	if (!(nb1 == '9' && nb2 == '8'))
	{
		ft_put2char(',', ' ');
	}
}

void	ft_display(char nb1, char nb2, char nb3, char nb4)
{
	if ((nb1 + nb2) < (nb3 + nb4))
	{
		ft_put2char(nb1, nb2);
		ft_putchar(' ');
		ft_put2char(nb3, nb4);
		ft_coma(nb1, nb2);
	}
}

void	ft_print_comb2(void)
{
	char	nb1;
	char	nb2;
	char	nb3;
	char	nb4;

	nb1 = '0' - 1;
	while (++nb1 <= '9')
	{
		nb2 = '0' - 1;
		while (++nb2 <= '9')
		{
			nb3 = '0' - 1;
			while (++nb3 <= '9')
			{
				nb4 = '0' - 1;
				while (++nb4 <= '9')
				{
					ft_display(nb1, nb2, nb3, nb4);
				}
			}
		}
	}
}
