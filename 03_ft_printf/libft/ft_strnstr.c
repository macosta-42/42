/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:10:16 by macosta           #+#    #+#             */
/*   Updated: 2020/05/02 14:38:31 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*n;
	size_t		nlen;

	nlen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len != 0)
	{
		if (*needle != *haystack)
		{
			haystack++;
			len--;
		}
		n = needle;
		while (*n == *haystack && len != 0)
		{
			haystack++;
			n++;
			len--;
			if (*n == '\0')
				return ((char *)(haystack - nlen));
		}
	}
	return (NULL);
}
