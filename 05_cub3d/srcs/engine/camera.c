/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:24:15 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 09:24:33 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_turn_right(t_params *dt)
{
	dt->player.old_dir_x = dt->player.dir_x;
	dt->player.dir_x = dt->player.dir_x * cos(dt->player.rtspeed) -
		dt->player.dir_y * sin(dt->player.rtspeed);
	dt->player.dir_y = dt->player.old_dir_x * sin(dt->player.rtspeed) +
		dt->player.dir_y * cos(dt->player.rtspeed);
	dt->player.old_plane_x = dt->player.plane_x;
	dt->player.plane_x = dt->player.plane_x * cos(dt->player.rtspeed) -
		dt->player.plane_y * sin(dt->player.rtspeed);
	dt->player.plane_y = dt->player.old_plane_x * sin(dt->player.rtspeed) +
		dt->player.plane_y * cos(dt->player.rtspeed);
}

void	ft_turn_left(t_params *dt)
{
	dt->player.old_dir_x = dt->player.dir_x;
	dt->player.dir_x = dt->player.dir_x * cos(-dt->player.rtspeed) -
		dt->player.dir_y * sin(-dt->player.rtspeed);
	dt->player.dir_y = dt->player.old_dir_x * sin(-dt->player.rtspeed) +
		dt->player.dir_y * cos(-dt->player.rtspeed);
	dt->player.old_plane_x = dt->player.plane_x;
	dt->player.plane_x = dt->player.plane_x * cos(-dt->player.rtspeed) -
		dt->player.plane_y * sin(-dt->player.rtspeed);
	dt->player.plane_y = dt->player.old_plane_x * sin(-dt->player.rtspeed) +
		dt->player.plane_y * cos(-dt->player.rtspeed);
}
