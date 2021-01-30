/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:41:06 by macosta           #+#    #+#             */
/*   Updated: 2020/05/07 23:28:52 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	if (srclen < dstsize)
		ft_memcpy(dst, src, (srclen + 1));
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, (dstsize - 1));
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
