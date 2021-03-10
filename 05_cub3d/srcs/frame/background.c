/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:04:18 by macosta           #+#    #+#             */
/*   Updated: 2020/10/29 04:10:08 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_background_color(t_params *dt, char *area, int start,
		int stop)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	if (!ft_strncmp(area, "ceiling", 8))
		color = dt->win.color_ceiling;
	if (!ft_strncmp(area, "floor", 6))
		color = dt->win.color_floor;
	while (++x < dt->win.screenwidth)
	{
		y = start - 1;
		while (++y < stop)
		{
			if (dt->img.address[(4 * x) + (y * dt->img.size_line)] == 0)
				ft_color_address(dt, x, y, color);
		}
	}
}
