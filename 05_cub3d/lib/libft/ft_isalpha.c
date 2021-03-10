/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:25:46 by macosta           #+#    #+#             */
/*   Updated: 2020/05/06 16:39:50 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z' ? 1 : 0);
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z' ? 1 : 0);
}

int			ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c) ? 1 : 0);
}
