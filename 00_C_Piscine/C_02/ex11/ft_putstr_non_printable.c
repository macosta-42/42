/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:52:25 by macosta           #+#    #+#             */
/*   Updated: 2020/02/10 18:33:12 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	const	char	*hex = "0123456789abcdef";

	i = 0;
	while (str[i] != '\0')
	{
		if (((str[i] <= 31) && (str[i] >= 1)) || (str[i] == 127))
		{
			ft_putchar('\\');
			ft_putchar(hex[str[i] / 16]);
			ft_putchar(hex[str[i] % 16]);
			i++;
		}
		ft_putchar(str[i]);
		i++;
	}
}
