/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:15:46 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 09:15:33 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_root_error(t_params *dt, int error_nb,
			void (*error_ft)(t_params *, int))
{
	error_ft(dt, error_nb);
}

void	ft_parsing_error_mngt(t_params *dt, int error_nb)
{
	write(1, "Error\n", 6);
	if (error_nb == 0)
		write(1, "resolution data collect\n", 24);
	if (error_nb == 1)
		write(1, "parsing allocation error\n", 25);
	if (error_nb == 2)
		write(1, "resolution data collected more than one time\n", 45);
	if (error_nb == 3)
		write(1, "undefined setting data\n", 23);
	if (error_nb == 4)
		write(1, "texture path data collect\n", 26);
	if (error_nb == 5)
		write(1, "same texture path is displayed twice or more\n", 45);
	if (error_nb == 6)
		write(1, "color data collect\n", 20);
	if (error_nb == 7)
		write(1, "color data collected more than one time\n", 40);
	if (error_nb == 8)
		write(1, "some data is missing in .cub file\n", 34);
	if (error_nb == 9)
		write(1, "allocation error\n", 17);
	if (error_nb == 10)
		write(1, "resolution data is displayed twice or more\n", 43);
	ft_clean_n_free(dt);
	exit(EXIT_SUCCESS);
}

void	ft_file_error_mngt(t_params *dt, int error_nb)
{
	write(1, "Error\n", 6);
	if (error_nb == 0)
		write(1, "data file (.cub) is missing\n", 28);
	if (error_nb == 1)
		write(1, "only <.cub> and <--save> arguments are expected\n", 48);
	if (error_nb == 2)
		write(1, "at .cub file opening\n", 21);
	if (error_nb == 3)
		write(1, "at texture file opening\n", 24);
	if (error_nb == 4)
		write(1, "at screenshot file creation or opening\n", 39);
	if (error_nb == 5)
		write(1, "too much arguments\n", 19);
	if (error_nb == 6)
		write(1, "data file has to be <.cub>\n", 27);
	ft_clean_n_free(dt);
	exit(EXIT_SUCCESS);
}

void	ft_map_error_mngt(t_params *dt, int error_nb)
{
	write(1, "Error\n", 6);
	if (error_nb == 0)
		write(1, "only [1] are allowed in map first and last line\n", 48);
	if (error_nb == 1)
		write(1, "map direction is defined more than one time\n", 44);
	if (error_nb == 2)
		write(1, "map direction is not defined\n", 29);
	if (error_nb == 3)
		write(1, "undefined data in the map\n", 26);
	if (error_nb == 4)
		write(1, "all the map is not close by a wall [1]\n", 39);
	if (error_nb == 5)
		write(1, "map line empty or only with space caracteres\n", 45);
	if (error_nb == 6)
		write(1, "map allocation error\n", 21);
	ft_clean_n_free(dt);
	exit(EXIT_SUCCESS);
}

void	ft_mlx_error_mngt(t_params *dt, int error_nb)
{
	write(1, "Error\n", 6);
	if (error_nb == 0)
		write(1, "at mlx initialisation\n", 22);
	if (error_nb == 1)
		write(1, "at mlx new window creation\n", 27);
	if (error_nb == 2)
		write(1, "at imagemlx initialisation\n", 22);
	ft_clean_n_free(dt);
	exit(EXIT_SUCCESS);
}
