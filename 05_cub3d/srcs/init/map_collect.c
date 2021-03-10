/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:30:13 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 08:58:08 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_data_collect_checker(t_params *dt)
{
	if (!(dt->screenresolution_collected == 1 &&
				dt->nowalltextpath_collected == 1 &&
				dt->sowalltextpath_collected == 1 &&
				dt->eawalltextpath_collected == 1 &&
				dt->wewalltextpath_collected == 1 &&
				dt->sptextpath_collected == 1 &&
				dt->color_ceiling_collected == 1 &&
				dt->color_floor_collected == 1))
	{
		dt->error_nb = 8;
		dt->error_ft = ft_parsing_error_mngt;
	}
}

void		ft_map_collect(char **line, t_params *dt)
{
	char *s;
	char *str;

	if (dt->is_map_started == FALSE)
	{
		ft_data_collect_checker(dt);
		if (!(dt->maptemp = ft_strdup(*line)))
			ft_root_error(dt, 6, ft_map_error_mngt);
		dt->is_map_started = TRUE;
	}
	else
	{
		if (!(str = ft_strjoin(dt->maptemp, "/")))
			ft_root_error(dt, 6, ft_map_error_mngt);
		free(dt->maptemp);
		if (!(s = ft_strdup(*line)))
			ft_root_error(dt, 6, ft_map_error_mngt);
		if (!(dt->maptemp = ft_strjoin(str, s)))
			ft_root_error(dt, 6, ft_map_error_mngt);
		free(s);
		free(str);
	}
}
