/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 06:58:06 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 06:58:31 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_loop_manager(void *data)
{
	t_params	*dt;

	dt = (t_params*)data;
	if (dt->img.id)
		mlx_destroy_image(dt->win.mlx_id, dt->img.id);
	ft_fillin_image(dt);
	ft_key_manager(dt);
	return (0);
}
