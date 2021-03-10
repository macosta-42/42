/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 02:03:05 by macosta           #+#    #+#             */
/*   Updated: 2020/11/07 06:10:30 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_start_n_end(t_params *dt)
{
	if (dt->ray.side == 0)
	{
		dt->ray.persp_wall_dist = (dt->ray.map_x - dt->player.pos_x +
			(1 - dt->ray.step_x) / 2) / dt->ray.dir_x;
		dt->texture.wall_x = dt->player.pos_y + dt->ray.persp_wall_dist *
			dt->ray.dir_y;
	}
	else
	{
		dt->ray.persp_wall_dist = (dt->ray.map_y - dt->player.pos_y +
				(1 - dt->ray.step_y) / 2) / dt->ray.dir_y;
		dt->texture.wall_x = dt->player.pos_x + dt->ray.persp_wall_dist *
			dt->ray.dir_x;
	}
	dt->texture.wall_x -= floor(dt->texture.wall_x);
	dt->texture.wall_x = 1 - dt->texture.wall_x;
	dt->ray.line_height = (int)(dt->win.screenheight / dt->ray.persp_wall_dist);
	dt->ray.draw_start = -dt->ray.line_height / 2 + dt->win.screenheight / 2;
	dt->ray.draw_end = dt->ray.line_height / 2 + dt->win.screenheight / 2;
}

static void	ft_wall_dist(t_params *dt)
{
	dt->ray.hit = 0;
	dt->ray.side = 0;
	while (dt->ray.hit == 0)
	{
		if (dt->ray.side_dist_x < dt->ray.side_dist_y)
		{
			dt->ray.side_dist_x += dt->ray.delta_dist_x;
			dt->ray.map_x += dt->ray.step_x;
			dt->ray.side = 0;
		}
		else
		{
			dt->ray.side_dist_y += dt->ray.delta_dist_y;
			dt->ray.map_y += dt->ray.step_y;
			dt->ray.side = 1;
		}
		if (dt->map.maptab[dt->ray.map_y][dt->ray.map_x] == '1')
			dt->ray.hit = 1;
	}
}

static void	ft_step_n_side_dist(t_params *dt)
{
	if (dt->ray.dir_x < 0.0)
	{
		dt->ray.step_x = -1;
		dt->ray.side_dist_x = (dt->player.pos_x - dt->ray.map_x) *
			dt->ray.delta_dist_x;
	}
	else
	{
		dt->ray.step_x = 1;
		dt->ray.side_dist_x = (dt->ray.map_x + 1.0 - dt->player.pos_x) *
			dt->ray.delta_dist_x;
	}
	if (dt->ray.dir_y < 0.0)
	{
		dt->ray.step_y = -1;
		dt->ray.side_dist_y = (dt->player.pos_y - dt->ray.map_y) *
			dt->ray.delta_dist_y;
	}
	else
	{
		dt->ray.step_y = 1;
		dt->ray.side_dist_y = (dt->ray.map_y + 1.0 - dt->player.pos_y) *
			dt->ray.delta_dist_y;
	}
}

static void	ft_ray_pos_n_dir(t_params *dt, int x)
{
	dt->ray.camera_x = 2 * x / (double)dt->win.screenwidth - 1;
	dt->ray.dir_x = dt->player.dir_x + dt->player.plane_x * dt->ray.camera_x;
	dt->ray.dir_y = dt->player.dir_y + dt->player.plane_y * dt->ray.camera_x;
	dt->ray.map_x = (int)dt->player.pos_x;
	dt->ray.map_y = (int)dt->player.pos_y;
	dt->ray.delta_dist_x = fabs(1 / dt->ray.dir_x);
	dt->ray.delta_dist_y = fabs(1 / dt->ray.dir_y);
}

void		ft_display_wall(t_params *dt)
{
	int	x;
	int	y;
	int	text_nb;

	x = -1;
	while (++x < dt->win.screenwidth)
	{
		ft_ray_pos_n_dir(dt, x);
		ft_step_n_side_dist(dt);
		ft_wall_dist(dt);
		ft_start_n_end(dt);
		y = dt->ray.draw_start - 1;
		if (y < -1)
			y = -1;
		text_nb = wall_texture_root(dt);
		while (++y < dt->ray.draw_end && y < dt->win.screenheight)
		{
			dt->texture.text_x = (int)(dt->texture.wall_x *
				dt->text[text_nb].width);
			dt->texture.text_y = (int)((y - dt->ray.draw_start) / (double)(dt->
				ray.draw_end - dt->ray.draw_start) * dt->text[text_nb].height);
			ft_colortexture_address(dt, x, y, text_nb);
		}
		dt->ray.z_buffer[x] = dt->ray.persp_wall_dist;
	}
}
