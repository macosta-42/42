/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:43:39 by macosta           #+#    #+#             */
/*   Updated: 2020/02/27 14:53:53 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 1;
		while (base[i + j])
		{
			if (base[j] == '\t' || base[j] == '\n' || base[j] == '\f' ||
				base[j] == '\v' || base[j] == '\r' || base[j] == ' ' ||
				base[j] == '+' || base[j] == '-')
				return (0);
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_getnb(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
	{
		i++;
	}
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

int	ft_scndcheck(char *str, char *base_from, int i)
{
	int	nb;

	nb = 0;
	while (str[i])
	{
		if (ft_getnb(str[i], base_from) == -1)
			return (nb);
		nb = (nb * ft_check_base(base_from)) + (ft_getnb(str[i], base_from));
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base_from)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	if (!(ft_check_base(base_from)))
		return (0);
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n' || str[i] == 32 ||
			str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nb = ft_scndcheck(str, base_from, i);
	return (nb * sign);
}
