/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:25:46 by macosta           #+#    #+#             */
/*   Updated: 2021/05/31 16:46:49 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (ft_ternary_i(c >= 'A' && c <= 'Z', 1, 0));
}

static int	ft_islower(int c)
{
	return (ft_ternary_i(c >= 'a' && c <= 'z', 1, 0));
}

int	ft_isalpha(int c)
{
	return (ft_ternary_i(ft_isupper(c) || ft_islower(c), 1, 0));
}
