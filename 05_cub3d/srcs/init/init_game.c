/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:03:52 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 07:22:11 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_root_collect(char *line, t_params *dt)
{
	int	i;

	i = 0;
	while (ft_is_space(line[i]) == 1)
		i++;
	if (line[i] == 'R' && line[i + 1] && !dt->is_map_started)
		ft_resolution_collect(line, dt);
	else if (((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'W' &&
			line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A') ||
			(line[i] == 'S')) && !dt->is_map_started)
		ft_texture_collect(line, dt);
	else if ((line[i] == 'F' || line[i] == 'C') && !dt->is_map_started)
		ft_color_collect(line, dt);
	else if (ft_isdigit(line[i]) == 1)
		ft_map_collect(&line, dt);
	else if (line[i])
	{
		dt->error_nb = 3;
		dt->error_ft = ft_parsing_error_mngt;
	}
	else if (!line[i] && dt->is_map_started == 1)
	{
		dt->error_nb = 5;
		dt->error_ft = ft_map_error_mngt;
	}
}

static void	ft_check_extention(t_params *dt, char *file_name, int len)
{
	int		i;
	char	*ext;

	i = -1;
	ext = ft_strdup("buc.");
	while (ext[++i] && file_name[--len] && i < 4)
	{
		if (!(ft_strrchr(&file_name[len], ext[i])))
		{
			free(ext);
			free(file_name);
			ft_file_error_mngt(dt, 6);
		}
	}
	free(ext);
}

static void	ft_args_mngt(int ac, char **av, t_params *dt)
{
	int		len;
	char	*file_name;

	len = 0;
	if (ac < 2)
		ft_file_error_mngt(dt, 0);
	file_name = ft_strdup(av[1]);
	len = ft_strlen(file_name);
	if (ac == 3 && !ft_strncmp(av[2], "--save", 7))
		dt->has_to_save = 1;
	else if (ac == 3)
		dt->error_nb = 1;
	else if (ac > 3)
		dt->error_nb = 5;
	ft_check_extention(dt, file_name, len);
	if (dt->error_nb != -1)
		dt->error_ft = ft_file_error_mngt;
	free(file_name);
}

void		ft_init_game(int ac, char **av, t_params *dt)
{
	int		fd;
	int		r;
	char	*line;

	line = 0;
	dt->error_nb = -1;
	ft_args_mngt(ac, av, dt);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_file_error_mngt(dt, 2);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		ft_root_collect(line, dt);
		free(line);
	}
	free(line);
	close(fd);
	if (!(dt->map.maptab = ft_split(dt->maptemp, '/')))
		ft_root_error(dt, 6, ft_map_error_mngt);
	dt->sprite_nb = ft_sprite_counter(dt);
	free(dt->maptemp);
	ft_player_position_collect(dt);
	ft_map_checker(dt);
	ft_sprite_position_collect(dt);
	dt->player.speed = 0.12;
	dt->player.rtspeed = 0.1;
}
