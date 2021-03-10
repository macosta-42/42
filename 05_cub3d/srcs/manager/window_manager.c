/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 06:50:08 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 06:52:58 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_event_destroy_window(void *data)
{
	t_params *dt;

	dt = (t_params*)data;
	if (dt->img.id)
		mlx_destroy_image(dt->win.mlx_id, dt->img.id);
	mlx_destroy_window(dt->win.mlx_id, dt->win.id);
	ft_free_struct(dt);
	free(dt->win.mlx_id);
	exit(EXIT_SUCCESS);
	return (0);
}
