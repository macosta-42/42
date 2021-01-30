/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:10:59 by macosta           #+#    #+#             */
/*   Updated: 2020/05/05 15:49:00 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + len2 + 1))))
		return (NULL);
	ft_memset(str, 0, (len + len2 + 1));
	ft_memcpy(str, s1, len);
	ft_memcpy(str + len, s2, len2);
	return (str);
}
