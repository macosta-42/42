/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 10:02:25 by macosta           #+#    #+#             */
/*   Updated: 2020/05/13 17:13:28 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*charptr;
	size_t		i;

	if (!str)
		return (0);
	charptr = str;
	i = 0;
	while (*charptr++)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dupli;
	int		i;

	i = 0;
	if (!(dupli = malloc(ft_strlen(src) + 1)))
		return (dupli);
	while (src[i])
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = 0;
	return (dupli);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	new_str_len;
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (new_str_len + 1))))
		return (NULL);
	while (s1[i] != '\0')
		new[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = (char)s2[j++];
	new[i] = '\0';
	return (new);
}

int		ft_strchr(const char *str, int c)
{
	while (*str)
		if (*str++ == (char)c)
			return (1);
	if (*str == (char)c)
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*toreturn;
	int		i;

	i = 0;
	if (!s || !(toreturn = (char*)malloc(len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
		while (s[start + i] && len--)
		{
			toreturn[i] = s[start + i];
			i++;
		}
	toreturn[i] = 0;
	return (toreturn);
}
