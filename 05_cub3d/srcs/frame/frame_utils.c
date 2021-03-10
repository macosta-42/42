/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:11:18 by macosta           #+#    #+#             */
/*   Updated: 2020/11/07 04:22:42 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_color_address(t_params *dt, int x, int y, int color)
{
	dt->img.address[(4 * x) + (y * dt->img.size_line) + 0] =
		(color & 0xFF);
	dt->img.address[(4 * x) + (y * dt->img.size_line) + 1] =
		((color & 0xFF00) >> 8);
	dt->img.address[(4 * x) + (y * dt->img.size_line) + 2] =
		((color & 0xFF0000) >> 16);
}

void	ft_colortexture_address(t_params *dt, int x, int y, int text_nb)
{
	int text_offset;
	int img_offset;

	img_offset = y * dt->img.size_line + x * dt->img.bits_per_pixel / 8;
	text_offset = dt->texture.text_y * dt->text[text_nb].size_line +
		dt->texture.text_x * (dt->text[text_nb].bits_per_pixel / 8);
	if (text_nb > 3)
		dt->sp_drwn.color = dt->text[text_nb].address[text_offset] +
			dt->text[text_nb].address[text_offset + 1] +
			dt->text[text_nb].address[text_offset + 2];
	if (text_nb < 4 || (text_nb > 3 && dt->sp_drwn.color != 0))
	{
		dt->img.address[img_offset] = dt->text[text_nb].address[text_offset];
		dt->img.address[img_offset + 1] =
			dt->text[text_nb].address[text_offset + 1];
		dt->img.address[img_offset + 2] =
			dt->text[text_nb].address[text_offset + 2];
	}
}
