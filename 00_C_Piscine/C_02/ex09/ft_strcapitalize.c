/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:34:56 by macosta           #+#    #+#             */
/*   Updated: 2020/02/10 13:32:21 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_is_alpha(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

char	ft_is_alphanumeric(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

char	ft_is_numeric(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '\0')
		return (str);
	if ((str[0] >= 'a') && (str[0] <= 'z'))
		str[0] = str[0] - ('a' - 'A');
	while (str[i] != '\0')
	{
		if ((ft_is_alphanumeric(str[i - 1]) == 0) && (ft_is_alpha(str[i]) == 1))
		{
			if ((str[i] >= 'a') && (str[i] <= 'z'))
				str[i] = str[i] - ('a' - 'A');
		}
		if ((ft_is_alphanumeric(str[i - 1]) == 1) && (ft_is_alpha(str[i]) == 1))
		{
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
				str[i] = str[i] + ('a' - 'A');
		}
		i++;
	}
	return (str);
}
