/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycasting_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:42:26 by macosta           #+#    #+#             */
/*   Updated: 2020/11/04 01:55:11 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	int	ft_dist_player_sprite(t_params *dt, int i)
{
	int	dist_1;
	int	dist_2;

	dist_1 = ((dt->player.pos_x - dt->sp[i].x) * (dt->player.pos_x -
		dt->sp[i].x) + (dt->player.pos_y - dt->sp[i].y) *
		(dt->player.pos_y - dt->sp[i].y));
	dist_2 = ((dt->player.pos_x - dt->sp[i + 1].x) * (dt->player.pos_x -
		dt->sp[i + 1].x) + (dt->player.pos_y - dt->sp[i + 1].y) *
		(dt->player.pos_y - dt->sp[i + 1].y));
	if (dist_1 < dist_2)
		return (1);
	return (0);
}

void		ft_sprite_order(t_params *dt)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < dt->sprite_nb - 1)
	{
		j = i + 1;
		while (j < dt->sprite_nb)
		{
			if (ft_dist_player_sprite(dt, i) == TRUE)
			{
				tmp = dt->sp[i];
				dt->sp[i] = dt->sp[i + 1];
				dt->sp[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
