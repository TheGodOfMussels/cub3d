/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:28 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:29 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_struct_setup(t_game *p)
{
	p->size.x = 800;
	p->size.y = 600;
	p->half_h = p->size.y / 2;
	p->half_w = p->size.x / 2;
	p->rdelay = 30;
	p->fov = 66;
	p->half_fov = 0;
	p->rc_precision = 64;
	p->rc_incrementing = p->fov / p->size.x;
	p->half_fov = p->fov / 2;
}

void	ft_spawn(t_game *p)
{
	int	i;
	int	j;

	i = -1;
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			if (p->map[i][j] == 'N' || p->map[i][j] == 'S'
				|| p->map[i][j] == 'E' || p->map[i][j] == 'W')
			{
				p->spawn_x = j;
				p->spawn_y = i;
				if (p->map[i][j] == 'N')
					p->angle = 270;
				else if (p->map[i][j] == 'S')
					p->angle = 90;
				else if (p->map[i][j] == 'E')
					p->angle = 0;
				else if (p->map[i][j] == 'W')
					p->angle = 180;
			}
		}
	}
}

void	ft_push_tex(t_game *p)
{
	p->no.ptr = mlx_xpm_file_to_image(p->mlx, p->no.path,
			&p->no.width, &p->no.height);
	p->no.data = mlx_get_data_addr(p->no.ptr, &p->no.bpp,
			&p->no.size_line, &p->no.endian);
	p->ea.ptr = mlx_xpm_file_to_image(p->mlx, p->ea.path,
			&p->ea.width, &p->ea.height);
	p->ea.data = mlx_get_data_addr(p->ea.ptr, &p->ea.bpp,
			&p->ea.size_line, &p->ea.endian);
	p->so.ptr = mlx_xpm_file_to_image(p->mlx, p->so.path,
			&p->so.width, &p->so.height);
	p->so.data = mlx_get_data_addr(p->so.ptr, &p->so.bpp,
			&p->so.size_line, &p->so.endian);
	p->we.ptr = mlx_xpm_file_to_image(p->mlx, p->we.path,
			&p->we.width, &p->we.height);
	p->we.data = mlx_get_data_addr(p->we.ptr, &p->we.bpp,
			&p->we.size_line, &p->we.endian);
	p->no.currenty = 0;
	p->ea.currenty = 0;
	p->so.currenty = 0;
	p->we.currenty = 0;
}

void	ft_create_image(t_texture *img, t_game *p)
{
	img->ptr = mlx_new_image(p->mlx, p->size.x, p->size.y);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
}

void	ft_create_window(t_game *p)
{
	p->mlx = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx, p->size.x, p->size.y, "Cub3d");
	ft_create_image(&p->img, p);
	ft_push_tex(p);
}
