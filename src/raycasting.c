/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:29:02 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:29:02 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_direction(t_game *p, t_ray *ray)
{
	if (ray->raycos < 0)
		ray->raycos *= -1;
	if (ray->raysin < 0)
		ray->raysin *= -1;
	if (p->map[(int)((ray->currenty)
			- ray->raysin)][(int)ray->currentx] != '1')
		ray->direction = 0;
	else if (p->map[(int)((ray->currenty)
			+ ray->raysin)][(int)ray->currentx] != '1')
		ray->direction = 1;
	else if (p->map[(int)(ray->currenty)][(int)((ray->currentx)
			+ ray->raycos)] != '1')
		ray->direction = 2;
	else if (p->map[(int)(ray->currenty)][(int)((ray->currentx)
			- ray->raycos)] != '1')
		ray->direction = 3;
}

static t_column	ft_do_column(t_game *p, t_ray ray, int raycount)
{
	t_column	res;

	res.sky_start = 0;
	res.sky_end = p->half_h - ray.wallheight;
	if (res.sky_end < 0)
		res.sky_end = 0;
	res.sky_color = ft_color_converter(p->color[1].r, p->color[1].g,
			p->color[1].b);
	res.wall_start = p->half_h - ray.wallheight;
	if (res.wall_start < 0)
		res.wall_start = 0;
	res.wall_end = p->half_h + ray.wallheight;
	if (res.wall_end >= p->size.y)
		res.wall_end = p->size.y;
	res.direction = ray.direction;
	res.floor_start = p->half_h + ray.wallheight;
	if (res.floor_start >= p->size.y)
		res.floor_start = p->size.y;
	res.floor_end = p->size.y;
	res.colnbr = raycount;
	res.currentx = ray.currentx;
	res.currenty = ray.currenty;
	res.floor_color = ft_color_converter(p->color[0].r, p->color[0].g,
			p->color[0].b);
	return (res);
}

static void	ft_init_ray(t_game *p, t_ray *ray)
{
	ray->currentx = p->spawn_x;
	ray->currenty = p->spawn_y;
	ray->raycos = cos(ft_degrees_to_radiants(ray->ray_angle))
		/ p->rc_precision;
	ray->raysin = sin(ft_degrees_to_radiants(ray->ray_angle))
		/ p->rc_precision;
}

static void	ft_raycasting2(t_game *p, t_ray *ray)
{
	int	wall;

	wall = 48;
	ft_init_ray(p, ray);
	while (wall == 48 || ft_is_direction(wall) == 1)
	{
		ray->currentx += ray->raycos;
		ray->currenty += ray->raysin;
		wall = p->map[(int)floor(ray->currenty)][(int)floor(ray->currentx)];
	}
}

void	ft_raycasting(t_game *p)
{
	int			raycount;
	t_ray		ray;
	t_column	currentcol;

	raycount = 0;
	ray.ray_angle = p->angle - p->half_fov;
	while (raycount < p->size.x)
	{
		ft_raycasting2(p, &ray);
		ray.dist = sqrt(pow(p->spawn_x - ray.currentx, 2) + pow(p->spawn_y
					- ray.currenty, 2));
		ray.dist = ray.dist * cos(ft_degrees_to_radiants(ray.ray_angle
					- p->angle));
		ray.wallheight = floor(p->half_h / ray.dist);
		ft_get_direction(p, &ray);
		currentcol = ft_do_column(p, ray, raycount);
		ft_render_full_column(p, p->img, currentcol);
		ray.ray_angle += p->rc_incrementing;
		raycount++;
	}
}
