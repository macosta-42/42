/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:52:34 by macosta           #+#    #+#             */
/*   Updated: 2020/02/27 11:36:16 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[i] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '\f' || base[i] == '\n'\
		|| base[i] == '\r' || base[i] == '\t' || base[i] == '\v')
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] == base[j])
			return (1);
		j = i + 1;
		while (base[i] != base[j] && base[j] != '\0')
			j++;
		i++;
	}
	if (i == 1)
		return (1);
	return (j);
}

int	ft_index_check(char c, char *base)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != c && base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_spacing(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'\
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	negate;
	int	i;
	int size;

	negate = 1;
	result = 0;
	i = 0;
	size = ft_base_check(base);
	if (size == 1)
		return (0);
	i = ft_spacing(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negate *= -1;
		i++;
	}
	while (ft_index_check(str[i], base) < size
		&& ft_index_check(str[i], base) != 0)
		result = (result * size) + (ft_index_check(str[i++], base));
	return (result * negate);
}
