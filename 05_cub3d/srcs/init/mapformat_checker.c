/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapformat_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 05:35:36 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 10:56:41 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_map_size(t_params *dt)
{
	int	i;
	int	width;

	i = 0;
	dt->map.mapwidth = ft_strlen(dt->map.maptab[0]);
	while (dt->map.maptab[i++])
		dt->map.mapheight++;
	i = 1;
	while (i < dt->map.mapheight)
	{
		if ((width = ft_strlen(dt->map.maptab[i])) > dt->map.mapwidth)
			dt->map.mapwidth = width;
		i++;
	}
}

static void	ft_map_caractere_checker(t_params dt)
{
	int	i;
	int	j;

	i = 0;
	while (dt.map.maptab[i] && (i < dt.map.mapheight))
	{
		j = 0;
		while (dt.map.maptab[i][j] && (j < dt.map.mapwidth))
		{
			if (ft_strchr(DIRECTIONS, dt.map.maptab[i][j]) == 0 &&
					ft_strchr(DESCRIPTIONS, dt.map.maptab[i][j]) == 0)
				ft_map_error_mngt(&dt, 3);
			j++;
		}
		i++;
	}
}

static void	ft_map_checker_backtracking(int pos_x, int pos_y,
			char **map, t_params dt)
{
	int	i;
	int	checked;

	i = 0;
	checked = 'c';
	if (pos_x < 0 || pos_x > dt.map.mapwidth || pos_y < 0 ||
			pos_y > dt.map.mapheight - 1 || map[pos_y][pos_x] == ' ')
	{
		while (i < dt.map.mapheight)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
		ft_map_error_mngt(&dt, 4);
	}
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == checked)
		return ;
	map[pos_y][pos_x] = checked;
	ft_map_checker_backtracking(pos_x + 1, pos_y, map, dt);
	ft_map_checker_backtracking(pos_x - 1, pos_y, map, dt);
	ft_map_checker_backtracking(pos_x, pos_y + 1, map, dt);
	ft_map_checker_backtracking(pos_x, pos_y - 1, map, dt);
	return ;
}

char		**ft_duplicate_map(t_params *dt)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * dt->map.mapheight)))
		ft_map_error_mngt(dt, 6);
	while (i < dt->map.mapheight)
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(*tab) * (ft_strlen(dt->map.maptab[i])
				+ 1))))
			ft_map_error_mngt(dt, 6);
		while (dt->map.maptab[i][j] && j < dt->map.mapwidth)
		{
			tab[i][j] = dt->map.maptab[i][j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

void		ft_map_checker(t_params *dt)
{
	int		i;
	int		pos_x;
	int		pos_y;
	char	**tab;

	i = 0;
	pos_x = (int)(dt->player.pos_x - 0.5);
	pos_y = (int)(dt->player.pos_y - 0.5);
	ft_init_map_size(dt);
	ft_map_caractere_checker(*dt);
	tab = ft_duplicate_map(dt);
	ft_map_checker_backtracking(pos_x, pos_y, tab, *dt);
	i = 0;
	while (i < dt->map.mapheight)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
