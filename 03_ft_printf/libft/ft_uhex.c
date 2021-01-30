/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:14:13 by macosta           #+#    #+#             */
/*   Updated: 2020/06/12 18:14:17 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev(char *hex)
{
	int		i;
	char	tmp;

	i = -1;
	while (++i < (int)ft_strlen(hex) / 2)
	{
		tmp = hex[i];
		hex[i] = hex[ft_strlen(hex) - 1 - i];
		hex[ft_strlen(hex) - 1 - i] = tmp;
	}
}

char		*ft_uhex(unsigned int nb, char c)
{
	int		offset;
	char	*hex;
	int		i;

	if (!(hex = (char *)malloc(sizeof(*hex) * (8 + 1))))
		return (NULL);
	offset = (c == 'x' ? 87 : 55);
	i = 0;
	if (nb == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
	}
	else
	{
		while (nb != 0)
		{
			hex[i++] = (nb % 16 < 10 ? 48 + nb % 16 : offset + nb % 16);
			nb = nb / 16;
		}
		hex[i] = '\0';
		ft_rev(hex);
	}
	return (hex);
}
