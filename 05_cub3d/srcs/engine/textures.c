/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:58:56 by macosta           #+#    #+#             */
/*   Updated: 2020/11/11 03:21:14 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_image_creation(t_params *dt, int text_nb, char *path)
{
	if (!(dt->text[text_nb].id = mlx_xpm_file_to_image(dt->win.mlx_id,
		path, &dt->text[text_nb].width, &dt->text[text_nb].height)))
	{
		ft_unload_texture(dt);
		ft_file_error_mngt(dt, 3);
	}
	dt->text[text_nb].address = mlx_get_data_addr(dt->text[text_nb].id,
		&dt->text[text_nb].bits_per_pixel, &dt->text[text_nb].size_line,
		&dt->text[text_nb].endian);
}

void		ft_unload_texture(t_params *dt)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (dt->text[i].id)
			mlx_destroy_image(dt->win.mlx_id, dt->text[i].id);
	}
}

void		ft_load_texture(t_params *dt)
{
	int		text_nb;
	char	*path;

	text_nb = 0;
	while (text_nb < 5)
	{
		if (text_nb == 0)
			path = dt->eawalltexturepath;
		else if (text_nb == 1)
			path = dt->wewalltexturepath;
		else if (text_nb == 2)
			path = dt->sowalltexturepath;
		else if (text_nb == 3)
			path = dt->nowalltexturepath;
		else if (text_nb == 4)
			path = dt->spritetexturepath;
		ft_image_creation(dt, text_nb, path);
		text_nb++;
	}
}

int			wall_texture_root(t_params *dt)
{
	int	text_nb;

	text_nb = -1;
	if (dt->ray.side == 0 && dt->ray.step_x == 1)
		text_nb = 0;
	else if (dt->ray.side == 0 && dt->ray.step_x == -1)
		text_nb = 1;
	else if (dt->ray.side == 1 && dt->ray.step_y == 1)
		text_nb = 2;
	else if (dt->ray.side == 1 && dt->ray.step_y == -1)
		text_nb = 3;
	return (text_nb);
}
