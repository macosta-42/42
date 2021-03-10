/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_position_collect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 06:14:56 by macosta           #+#    #+#             */
/*   Updated: 2020/10/22 06:25:29 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_sprite	*ft_sprite_init(t_params *dt, int sprite_nb)
{
	t_sprite *sp;

	if (!(sp = (t_sprite*)malloc(sizeof(*sp) * sprite_nb)))
		ft_parsing_error_mngt(dt, 9);
	return (sp);
}

void			ft_sprite_position_collect(t_params *dt)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = -1;
	dt->sp = ft_sprite_init(dt, dt->sprite_nb);
	while (++y < dt->map.mapheight)
	{
		x = -1;
		while (++x < dt->map.mapwidth && dt->map.maptab[y][x])
		{
			if (dt->map.maptab[y][x] == '2')
			{
				dt->sp[++i].x = x;
				dt->sp[i].y = y;
			}
		}
	}
}
