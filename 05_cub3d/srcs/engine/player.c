/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:23:17 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 09:23:52 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_move_fwd(t_params *dt)
{
	if (dt->map.maptab[(int)(dt->player.pos_y)][(int)(dt->player.pos_x +
			dt->player.dir_x * dt->player.speed)] == '0')
		dt->player.pos_x += dt->player.dir_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y + dt->player.dir_y *
			dt->player.speed)][(int)(dt->player.pos_x)] == '0')
		dt->player.pos_y += dt->player.dir_y * dt->player.speed;
}

void	ft_move_bkwd(t_params *dt)
{
	if (dt->map.maptab[(int)(dt->player.pos_y)][(int)(dt->player.pos_x -
			dt->player.dir_x * dt->player.speed)] == '0')
		dt->player.pos_x -= dt->player.dir_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y - dt->player.dir_y *
			dt->player.speed)][(int)(dt->player.pos_x)] == '0')
		dt->player.pos_y -= dt->player.dir_y * dt->player.speed;
}

void	ft_move_right(t_params *dt)
{
	if (dt->map.maptab[(int)dt->player.pos_y][(int)(dt->player.pos_x +
			dt->player.plane_x * dt->player.speed)] == '0')
		dt->player.pos_x += dt->player.plane_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y + dt->player.plane_y *
			dt->player.speed)][(int)dt->player.pos_x] == '0')
		dt->player.pos_y += dt->player.plane_y * dt->player.speed;
}

void	ft_move_left(t_params *dt)
{
	if (dt->map.maptab[(int)dt->player.pos_y][(int)(dt->player.pos_x -
			dt->player.plane_x * dt->player.speed)] == '0')
		dt->player.pos_x -= dt->player.plane_x * dt->player.speed;
	if (dt->map.maptab[(int)(dt->player.pos_y - dt->player.plane_y *
			dt->player.speed)][(int)dt->player.pos_x] == '0')
		dt->player.pos_y -= dt->player.plane_y * dt->player.speed;
}
