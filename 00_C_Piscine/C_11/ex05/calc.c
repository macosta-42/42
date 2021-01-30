/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:56:49 by macosta           #+#    #+#             */
/*   Updated: 2020/02/25 22:44:38 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_calc(char *str1, char c, char *str2)
{
	void	(*f[5])(int, int);

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_mult;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	if (c != '+' && c != '-' && c != '*' && c != '/' && c != '%')
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	if (c == '+')
		f[0](ft_atoi(str1), ft_atoi(str2));
	if (c == '-')
		f[1](ft_atoi(str1), ft_atoi(str2));
	if (c == '*')
		f[2](ft_atoi(str1), ft_atoi(str2));
	if (c == '/')
		f[3](ft_atoi(str1), ft_atoi(str2));
	if (c == '%')
		f[4](ft_atoi(str1), ft_atoi(str2));
}
