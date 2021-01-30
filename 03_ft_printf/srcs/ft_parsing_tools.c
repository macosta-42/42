/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:07:32 by macosta           #+#    #+#             */
/*   Updated: 2020/07/04 15:18:49 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_format_width(const char *fmt, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	if (fmt[pos + i] == '*')
		return (ft_strdup("*"));
	while (ft_isdigit(fmt[pos + i]) && fmt[pos + i])
		i++;
	if (i != 0)
		return (ft_substr(fmt, pos, i));
	return (NULL);
}

char		*ft_format_precision(const char *fmt, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	if (fmt[pos + i] == '*')
		return (ft_strdup("*"));
	while (ft_isdigit(fmt[pos + i]) && fmt[pos + i])
		i++;
	if (i != 0)
		return (ft_substr(fmt, pos, i));
	return (NULL);
}

char		*ft_format_before(const char *fmt, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	while (fmt[pos + i] && fmt[pos + i] != '%')
		i++;
	if (i != 0)
		return (ft_substr(fmt, pos, i));
	return (NULL);
}

t_format	ft_format_flag(t_format f, const char *fmt, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	while ((fmt[pos + i] == '0' || fmt[pos + i] == '-') && fmt[pos + i])
	{
		while ((fmt[pos + i] == '0' && fmt[pos + i]))
		{
			if (f.flag != '-')
			{
				f.flag = fmt[pos + i];
				f.zero = 1;
			}
			i++;
		}
		while ((fmt[pos + i] == '-' && fmt[pos + i]))
		{
			f.flag = fmt[pos + i];
			i++;
		}
	}
	f.offsetflag = i;
	return (f);
}
