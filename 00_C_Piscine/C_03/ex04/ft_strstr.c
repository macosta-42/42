/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:11:51 by macosta           #+#    #+#             */
/*   Updated: 2020/02/11 17:12:18 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[j] != '\0')
	{
		if (to_find[i] != str[j])
			j++;
		i = 0;
		while (to_find[i] == str[j])
		{
			i++;
			j++;
			if (to_find[i] == '\0')
				return (str + (j - i));
		}
	}
	return ((char *)0);
}
