/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:52:40 by macosta           #+#    #+#             */
/*   Updated: 2021/05/31 18:01:53 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*new;

	count = -1;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s || !f || new == NULL)
		return (NULL);
	while (s[++count] != '\0')
		new[count] = f(count, (char)s[count]);
	new[count] = '\0';
	return (new);
}
