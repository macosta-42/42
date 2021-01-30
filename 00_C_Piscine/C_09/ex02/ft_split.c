/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:08:19 by macosta           #+#    #+#             */
/*   Updated: 2020/02/24 09:53:27 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int		count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset) == 0)
			str++;
		if (*str && ft_is_charset(*str, charset) == 1)
		{
			count++;
			while (*str && ft_is_charset(*str, charset) == 1)
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 1)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 1)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	if (!(tab = (char **)malloc(sizeof(char *)
				* (count_words(str, charset) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset) == 0)
			str++;
		if (*str && ft_is_charset(*str, charset) == 1)
		{
			tab[i] = malloc_word(str, charset);
			i++;
			while (*str && ft_is_charset(*str, charset) == 1)
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
