/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:04:13 by macosta           #+#    #+#             */
/*   Updated: 2020/07/04 15:21:16 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_display_char(t_format *f, char c)
{
	char	*result;
	char	*offset;
	int		excp;

	if (c == 0 && f->flag != '-')
		f->excp = 3;
	if (c == 0 && f->flag == '-')
		f->excp = 2;
	excp = (c == 0 ? 1 : 0);
	if (!(result = (char *)malloc(sizeof(*result) * 2)))
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	if (f->width != NULL)
		f->width = ft_itoa(ft_atoi(f->width) - excp);
	if (f->conv == '%' && f->flag == '0' && f->width)
		result = ft_length(ft_itoa(ft_atoi(f->width)), result, 1);
	if ((offset = ft_offset(f->width, result)))
		result = (f->flag == '-' ? ft_strjoin_freed(result, offset) :
				ft_strjoin_freed(offset, result));
	return (result);
}

char	*ft_display_d_i(t_format f, char *str)
{
	char	*result;
	char	*offset;

	if (f.conv == 'p')
		str = ft_strjoin_freed(ft_strdup("0x"), str);
	if (f.precision && ft_strcmp(f.precision, "0") == 0 && f.conv != 'p')
	{
		if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "-0") == 0)
		{
			free(str);
			str = ft_strdup("");
		}
	}
	result = ft_length(f.precision, str, 0);
	if (!f.precision && f.flag == '0' && result[0] == '-' && f.width)
		result = ft_length(ft_itoa(ft_atoi(f.width) - 1), result, 1);
	else if (!f.precision && f.flag == '0' && f.width)
		result = ft_length(f.width, result, 0);
	else if ((offset = ft_offset(f.width, result)))
		result = (f.flag == '-' ? ft_strjoin_freed(result, offset) :
				ft_strjoin_freed(offset, result));
	return (result);
}

char	*ft_display_mem(t_format f, long arg)
{
	if (arg == 0)
	{
		if (f.precision && ft_strcmp(f.precision, "0") == 0)
			return (ft_display_d_i(f, ft_strdup("")));
		else
			return (ft_display_d_i(f, ft_strdup("0")));
	}
	return (ft_display_d_i(f, ft_lhex(arg, 'x')));
}

char	*ft_display_int(t_format *f, int arg)
{
	if (f->conv == 'c')
		return (ft_display_char(f, (char)arg));
	else if (f->conv == 'd' || f->conv == 'i')
		return (ft_display_d_i(*f, ft_itoa(arg)));
	else if (f->conv == 'u')
		return (ft_display_d_i(*f, ft_itoa_us(arg + 1 + 4294967295)));
	else if (f->conv == 'x' || f->conv == 'X')
		return (ft_display_d_i(*f, ft_uhex(arg + 1 + 4294967295, f->conv)));
	return (NULL);
}

char	*ft_display_str(t_format f, char *str)
{
	int		size;
	char	*result;
	char	*offset;
	int		flag;

	flag = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	else if (ft_strcmp(str, "") == 0)
	{
		str = ft_strdup("");
		flag = 1;
	}
	size = (f.precision ? ft_atoi(f.precision) : ft_strlen(str));
	result = ft_substr(str, 0, size);
	if (flag == 1)
		free(str);
	if ((offset = (f.zero == 0 ? ft_offset(f.width, result) :
				ft_offset_0(f.width, result))))
		result = (f.flag == '-' ? ft_strjoin_freed(result, offset) :
				ft_strjoin_freed(offset, result));
	return (result);
}
