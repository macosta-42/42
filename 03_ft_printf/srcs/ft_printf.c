/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:08:13 by macosta           #+#    #+#             */
/*   Updated: 2020/06/25 10:08:22 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_test_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'c' || c == 'u')
		return (1);
	return (0);
}

t_format		ft_format_result(va_list ap, t_format f)
{
	int star;

	f.result = NULL;
	if (f.width && ft_strcmp(f.width, "*") == 0)
	{
		star = va_arg(ap, int);
		f.flag = (star >= 0 ? f.flag : '-');
		free(f.width);
		f.width = (star >= 0 ? ft_itoa(star) : ft_itoa(star * -1));
	}
	if (f.precision && ft_strcmp(f.precision, "*") == 0)
	{
		star = va_arg(ap, int);
		free(f.precision);
		f.precision = (star >= 0 ? ft_itoa(star) : NULL);
	}
	if (ft_test_conv(f.conv) == 1)
		f.result = ft_display_int(&f, va_arg(ap, int));
	else if (f.conv == 'p')
		f.result = ft_display_mem(f, (long)va_arg(ap, void *));
	else if (f.conv == 's')
		f.result = ft_display_str(f, va_arg(ap, char *));
	else if (f.conv == '%')
		f.result = ft_display_char(&f, '%');
	return (f);
}

int				ft_print_result(t_format *f, int size)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	f[size].result = NULL;
	while (++i <= size)
	{
		if (f[i].before)
			ft_putstr(f[i].before);
		if (f[i].result)
		{
			if (f[i].excp == 2)
				ft_putchar(0);
			ft_putstr(f[i].result);
			if (f[i].excp == 3)
				ft_putchar(0);
			result += ((f[i].excp == 2 || f[i].excp == 3) ? 1 : 0);
		}
		result += ft_strlen(f[i].result);
		result += ft_strlen(f[i].before);
	}
	return (result);
}

void			ft_format_free(t_format *f, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (f[i].before)
			free(f[i].before);
		if (f[i].width)
			free(f[i].width);
		if (f[i].precision)
			free(f[i].precision);
		if (f[i].result)
			free(f[i].result);
		i++;
	}
	free(f[i].before);
	free(f[i].result);
	if (f)
		free(f);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	t_format	*f;
	int			result;

	if (format == NULL || (format[0] == '%' && ft_strlen(format) == 1))
		return (-1);
	f = ft_parsing(format);
	va_start(ap, format);
	i = -1;
	while (++i < (int)ft_count(format))
		f[i] = ft_format_result(ap, f[i]);
	va_end(ap);
	result = ft_print_result(f, (int)ft_count(format));
	ft_format_free(f, ft_count(format));
	return (result);
}
