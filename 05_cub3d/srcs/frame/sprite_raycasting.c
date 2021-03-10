/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:38:18 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 09:13:46 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_sprite_width_calc(t_params *dt)
{
	dt->sp_drwn.width = abs((int)((double)dt->win.screenheight /
		(dt->sp_drwn.transform_y)));
	dt->sp_drwn.draw_start_x = -dt->sp_drwn.width / 2 +
		dt->sp_drwn.screen_x;
	if (dt->sp_drwn.draw_start_x < 0)
		dt->sp_drwn.draw_start_x = 0;
	dt->sp_drwn.draw_end_x = dt->sp_drwn.width / 2 + dt->sp_drwn.screen_x;
	if (dt->sp_drwn.draw_end_x >= dt->win.screenwidth)
		dt->sp_drwn.draw_end_x = dt->win.screenwidth - 1;
}

static void	ft_sprite_calc(t_params *dt, int i)
{
	dt->sp_drwn.x = (double)dt->sp[i].x - (dt->player.pos_x - 0.5);
	dt->sp_drwn.y = (double)dt->sp[i].y - (dt->player.pos_y - 0.5);
	dt->sp_drwn.inv_det = 1.0 / (dt->player.plane_x * dt->player.dir_y -
		dt->player.dir_x * dt->player.plane_y);
	dt->sp_drwn.transform_x = dt->sp_drwn.inv_det * (dt->player.dir_y *
		dt->sp_drwn.x - dt->player.dir_x * dt->sp_drwn.y);
	dt->sp_drwn.transform_y = dt->sp_drwn.inv_det * (-dt->player.plane_y *
		dt->sp_drwn.x + dt->player.plane_x * dt->sp_drwn.y);
	dt->sp_drwn.screen_x = (int)(((double)dt->win.screenwidth / 2.0) *
		(1.0 + dt->sp_drwn.transform_x / dt->sp_drwn.transform_y));
	dt->sp_drwn.height = abs((int)((double)dt->win.screenheight /
		dt->sp_drwn.transform_y));
	dt->sp_drwn.draw_start_y = -(double)dt->sp_drwn.height / 2.0 +
		(double)dt->win.screenheight / 2.0;
	if (dt->sp_drwn.draw_start_y < 0)
		dt->sp_drwn.draw_start_y = 0;
	dt->sp_drwn.draw_end_y = (double)dt->sp_drwn.height / 2.0 +
		(double)dt->win.screenheight / 2.0;
	if (dt->sp_drwn.draw_end_y >= dt->win.screenheight)
		dt->sp_drwn.draw_end_y = dt->win.screenheight - 1;
	ft_sprite_width_calc(dt);
}

static void	ft_draw_sprite(t_params *dt, int x, int text_nb)
{
	int	y;
	int	d;

	y = dt->sp_drwn.draw_start_y - 1;
	d = 0;
	while (++y < dt->sp_drwn.draw_end_y)
	{
		d = y * dt->text[text_nb].size_line - dt->win.screenheight *
			dt->text[text_nb].size_line / 2 + dt->sp_drwn.height *
			dt->text[text_nb].size_line / 2;
		dt->texture.text_y = ((d * dt->text[text_nb].height) /
				dt->sp_drwn.height) / dt->text[text_nb].size_line;
		ft_colortexture_address(dt, x, y, text_nb);
	}
}

void		ft_display_sprite(t_params *dt)
{
	int	i;
	int	x;
	int	text_nb;

	i = -1;
	text_nb = 4;
	ft_sprite_order(dt);
	while (++i < dt->sprite_nb)
	{
		ft_sprite_calc(dt, i);
		x = dt->sp_drwn.draw_start_x - 1;
		while (++x < dt->sp_drwn.draw_end_x)
		{
			dt->texture.text_x = (int)(dt->text[4].size_line * (x -
				(-dt->sp_drwn.width / 2 + dt->sp_drwn.screen_x)) *
				dt->text[4].width / dt->sp_drwn.width) / dt->text[4].size_line;
			if (dt->sp_drwn.transform_y > 0.0 && x > 0 &&
					x < dt->win.screenwidth &&
					dt->sp_drwn.transform_y < dt->ray.z_buffer[x])
				ft_draw_sprite(dt, x, text_nb);
		}
	}
}
