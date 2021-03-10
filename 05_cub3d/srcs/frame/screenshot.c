/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:36:02 by macosta           #+#    #+#             */
/*   Updated: 2020/11/06 09:09:03 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_itoc(unsigned char *c, int i)
{
	ft_bzero(c, 4);
	c[0] = (unsigned char)i;
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

static void	ft_info_header(unsigned char *c, int width, int height)
{
	ft_itoc(c, 'B');
	c[1] = (unsigned char)'M';
	c[10] = (unsigned char)(54);
	c[14] = (unsigned char)(40);
	ft_itoc(c + 18, width);
	ft_itoc(c + 22, height);
	c[26] = (unsigned char)(1);
	c[28] = (unsigned char)(24);
}

static void	ft_write_img(t_params *dt, int fd, int oct_add,
				unsigned char oct_null)
{
	int				x;
	int				y;
	int				i;
	unsigned char	cp;

	y = dt->win.screenheight;
	while (--y >= 0)
	{
		x = -1;
		while (++x < dt->win.screenwidth)
		{
			i = -1;
			while (++i < 3)
			{
				cp = dt->img.address[x * 4 + y * dt->img.size_line + i];
				if (write(fd, &cp, 1) < 0)
					return ;
			}
		}
	}
	while (oct_add-- > 0)
	{
		if (write(fd, &oct_null, 1) < 0)
			return ;
	}
}

void		ft_create_bmp(t_params *dt)
{
	int				fd;
	int				oct_add;
	unsigned char	c[54];
	unsigned char	oct_null;

	oct_add = (54 + dt->win.screenwidth * 3 * dt->win.screenheight) % 4;
	oct_null = 0;
	ft_bzero(c, 54);
	if ((fd = open("cub3d.bmp", O_RDWR | O_CREAT, 00777 | O_APPEND)) < 0)
		ft_file_error_mngt(dt, 4);
	ft_info_header(c, dt->win.screenwidth, dt->win.screenheight);
	write(fd, c, 54);
	ft_write_img(dt, fd, oct_add, oct_null);
	close(fd);
}
