/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:02:15 by macosta           #+#    #+#             */
/*   Updated: 2020/05/03 15:26:08 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*haystack;
	unsigned char	needle;

	haystack = (unsigned char *)s;
	needle = (unsigned char)c;
	while (n-- != 0)
	{
		if (*haystack == needle)
			return ((void *)haystack);
		if (*haystack == '\0')
			return (NULL);
		haystack++;
	}
	return (NULL);
}
