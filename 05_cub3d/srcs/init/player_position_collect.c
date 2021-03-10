/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position_collect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 04:59:50 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 08:54:50 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_position(t_params *dt, int i, int j)
{
	dt->player.pos_x = j + 0.5;
	dt->player.pos_y = i + 0.5;
}

static void	ft_direction_collect(t_params *dt, char c)
{
	if (dt->is_position_defined == FALSE)
	{
		dt->direction = c;
		dt->is_position_defined = TRUE;
	}
	else
		ft_map_error_mngt(dt, 1);
}

static void	ft_init_direction(t_params *dt)
{
	if (dt->direction == 'S')
	{
		dt->player.dir_x = 0;
		dt->player.dir_y = 1;
	}
	if (dt->direction == 'N')
	{
		dt->player.dir_x = 0;
		dt->player.dir_y = -1;
	}
	if (dt->direction == 'E')
	{
		dt->player.dir_x = 1;
		dt->player.dir_y = 0;
	}
	if (dt->direction == 'W')
	{
		dt->player.dir_x = -1;
		dt->player.dir_y = 0;
	}
}

static void	ft_init_plane(t_params *dt)
{
	if (dt->direction == 'S')
	{
		dt->player.plane_x = -tanf((FOV / 180 * PI) / 2.0);
		dt->player.plane_y = 0.0;
	}
	if (dt->direction == 'N')
	{
		dt->player.plane_x = tanf((FOV / 180 * PI) / 2.0);
		dt->player.plane_y = 0.0;
	}
	if (dt->direction == 'E')
	{
		dt->player.plane_x = 0.0;
		dt->player.plane_y = tanf((FOV / 180 * PI) / 2.0);
	}
	if (dt->direction == 'W')
	{
		dt->player.plane_x = 0.0;
		dt->player.plane_y = -tanf((FOV / 180 * PI) / 2.0);
	}
}

void		ft_player_position_collect(t_params *dt)
{
	int	i;
	int	j;

	i = 0;
	while (dt->map.maptab[i])
	{
		j = 0;
		while (dt->map.maptab[i][j])
		{
			if (ft_strchr(DIRECTIONS, dt->map.maptab[i][j]))
			{
				ft_init_position(dt, i, j);
				ft_direction_collect(dt, (dt->map.maptab[i][j]));
				dt->map.maptab[i][j] = '0';
				ft_init_direction(dt);
				ft_init_plane(dt);
			}
			j++;
		}
		i++;
	}
	if (dt->is_position_defined == FALSE)
		ft_map_error_mngt(dt, 2);
}
