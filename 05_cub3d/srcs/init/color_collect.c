/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:43:52 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 08:53:06 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_rgb_to_int(char *colors, int *rgb, int ret)
{
	while (colors[ret] && colors[ret] != ',')
		ret++;
	ret++;
	*rgb = ft_atoi(colors + ret);
	return (ret);
}

static int	ft_strtoint_color(char *colors, int c, t_params *dt)
{
	int	red;
	int	green;
	int	blue;
	int	i;

	i = 0;
	if ((c == 'F' && dt->color_floor_collected == 1) ||
			(c == 'C' && dt->color_ceiling_collected == 1))
	{
		dt->error_nb = 7;
		dt->error_ft = ft_parsing_error_mngt;
	}
	red = ft_atoi(colors);
	i = ft_rgb_to_int(colors, &green, i);
	i = ft_rgb_to_int(colors, &blue, i);
	if (!((red >= 0 && red <= 255) && (green >= 0 && green <= 255) &&
				(blue >= 0 && blue <= 255)))
	{
		dt->error_nb = 6;
		dt->error_ft = ft_parsing_error_mngt;
	}
	return (red << 16 | green << 8 | blue);
}

static void	ft_color_root(int color, char c, t_params *dt)
{
	if (c == 'F')
	{
		dt->color_floor_collected = TRUE;
		dt->win.color_floor = color;
	}
	else if (c == 'C')
	{
		dt->color_ceiling_collected = TRUE;
		dt->win.color_ceiling = color;
	}
}

void		ft_color_collect(char *line, t_params *dt)
{
	int		i;
	char	c;
	char	*colors;

	i = 0;
	while (ft_is_space(line[i]) == 1)
		i++;
	c = line[i];
	if (!ft_is_color_format(dt, line))
	{
		dt->error_nb = 6;
		dt->error_ft = ft_parsing_error_mngt;
	}
	i++;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (!(colors = ft_strdup(line + i)))
	{
		dt->error_nb = 1;
		dt->error_ft = ft_parsing_error_mngt;
	}
	i = ft_strtoint_color(colors, c, dt);
	free(colors);
	ft_color_root(i, c, dt);
}
