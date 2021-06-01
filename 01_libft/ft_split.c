/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:58:04 by macosta           #+#    #+#             */
/*   Updated: 2021/05/31 17:25:43 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s1, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			count++;
		}
		s1++;
	}
	return (count);
}

static int	ft_wordlen(const char *s2, char c, int i)
{
	int	len;

	len = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_freemem(const char **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**ft_affect(const char *s, char **dst, char c, int words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * ft_wordlen(s, c, i) + 1);
		if (dst[j] == NULL)
			return (ft_freemem((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_wordcount(s, c);
	dst = (char **)malloc(sizeof(char *) * (words + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_affect(s, dst, c, words));
}
