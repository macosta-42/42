/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raga <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:32:16 by raga              #+#    #+#             */
/*   Updated: 2020/02/08 17:41:57 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_line(int largeur)
{
	int colonne;

	if (largeur > 0)
	{
		ft_putchar('A');
		colonne = 1;
		while (colonne <= largeur - 2)
		{
			ft_putchar('B');
			colonne++;
		}
	}
	if (largeur > 1)
	{
		ft_putchar('C');
	}
}

void	ft_middle_line(int largeur)
{
	int colonne;

	colonne = 1;
	if (largeur > 0)
	{
		ft_putchar('B');
		while (colonne <= (largeur - 2))
		{
			ft_putchar(' ');
			colonne++;
		}
	}
	if (largeur > 1)
	{
		ft_putchar('B');
	}
}

void	ft_latest_line(int largeur)
{
	int colonne;

	if (largeur > 0)
	{
		ft_putchar('C');
		colonne = 1;
		while (colonne <= (largeur - 2))
		{
			ft_putchar('B');
			colonne++;
		}
	}
	if (largeur > 1)
	{
		ft_putchar('A');
	}
}

void	rush(int x, int y)
{
	int line;

	line = 1;
	if ((x <= 0) || (y <= 0))
		return ;
	ft_first_line(x);
	ft_putchar('\n');
	while (++line <= y)
	{
		while (line < y)
		{
			ft_middle_line(x);
			ft_putchar('\n');
			line++;
		}
		if (line == y)
		{
			ft_latest_line(x);
			ft_putchar('\n');
		}
	}
}
