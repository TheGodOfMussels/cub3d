/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:29:19 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:29:19 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ren_col_piece(t_texture img, t_render render, int nb)
{
	while (render.start < render.end)
	{
		ft_render_pixel(img, nb, render.start, render.color);
		render.start++;
	}
}

void	ft_render_column(t_texture img, t_column column, int flag)
{
	t_render	render;

	if (flag == 0)
	{
		render.start = column.sky_start;
		render.end = column.sky_end;
		render.color = column.sky_color;
	}
	else if (flag == 1)
	{
		render.start = column.wall_start;
		render.end = column.wall_end;
		render.color = column.wall_color;
	}
	else
	{
		render.start = column.floor_start;
		render.end = column.floor_end;
		render.color = column.floor_color;
	}
	ft_ren_col_piece(img, render, column.colnbr);
}

void	ft_render_wall(t_texture *texture, t_texture img, t_column column)
{
	unsigned int	color;
	double			textx;
	double			stepx;
	double			texty;
	int				i;

	i = 0;
	stepx = (double)texture->height / (column.wall_end - column.wall_start);
	textx = 0;
	texty = (double)texture->width * (column.currentx + column.currenty);
	while (column.wall_start < column.wall_end)
	{
		color = ft_mlx_pixel_get
			(texture, (int)texty % texture->width,
				(int)textx % texture->height);
		ft_render_pixel(img, column.colnbr, column.wall_start, color);
		column.wall_start++;
		textx += stepx;
		i++;
	}
	texture->currenty += stepx / texture->width;
}

void	ft_render_walls(t_game *p, t_texture img, t_column column)
{
	if (column.direction == 0)
		ft_render_wall(&p->no, img, column);
	else if (column.direction == 1)
		ft_render_wall(&p->so, img, column);
	else if (column.direction == 2)
		ft_render_wall(&p->ea, img, column);
	else
		ft_render_wall(&p->we, img, column);
}

void	ft_render_full_column(t_game *p, t_texture img, t_column column)
{
	ft_render_column(img, column, 0);
	ft_render_walls(p, img, column);
	ft_render_column(img, column, 2);
}
