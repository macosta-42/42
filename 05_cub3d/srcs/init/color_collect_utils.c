/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_collect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:54:52 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 08:36:30 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_color_format_error(t_params *dt)
{
	dt->error_nb = 6;
	dt->error_ft = ft_parsing_error_mngt;
}

static int	ft_color_format(t_params *dt, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if ((str[i] && ft_isdigit(str[i]) == 0) || !str[i])
		ft_color_format_error(dt);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	return (i);
}

int			ft_is_color_format(t_params *dt, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	i++;
	if (line[i] != ' ')
		ft_color_format_error(dt);
	i += ft_color_format(dt, line + i);
	if (line[i] != ',')
		ft_color_format_error(dt);
	i++;
	i += ft_color_format(dt, line + i);
	if (line[i] != ',')
		ft_color_format_error(dt);
	i++;
	i += ft_color_format(dt, line + i);
	if (*(line + i))
		ft_color_format_error(dt);
	return (1);
}
