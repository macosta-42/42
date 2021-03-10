/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:20:19 by macosta           #+#    #+#             */
/*   Updated: 2020/10/20 12:20:30 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_free_maptab(char **maptab)
{
	int i;

	i = 0;
	if (maptab == NULL)
		return ;
	while (maptab[i])
	{
		free((maptab[i]));
		i++;
	}
	free(maptab);
}

void		ft_free_struct(t_params *dt)
{
	if (dt->map.maptab)
		ft_free_maptab(dt->map.maptab);
	if (dt->ray.z_buffer)
		free(dt->ray.z_buffer);
	if (dt->nowalltexturepath)
		free(dt->nowalltexturepath);
	if (dt->sowalltexturepath)
		free(dt->sowalltexturepath);
	if (dt->wewalltexturepath)
		free(dt->wewalltexturepath);
	if (dt->eawalltexturepath)
		free(dt->eawalltexturepath);
	if (dt->spritetexturepath)
		free(dt->spritetexturepath);
	if (dt->sp)
		free(dt->sp);
}

void		ft_clean_n_free(t_params *dt)
{
	if (dt->img.id)
		mlx_destroy_image(dt->win.mlx_id, dt->img.id);
	if (dt->win.id)
		mlx_destroy_window(dt->win.mlx_id, dt->win.id);
	ft_free_struct(dt);
	if (dt->win.mlx_id)
		free(dt->win.mlx_id);
}
