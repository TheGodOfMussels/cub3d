/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:29:29 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:29:29 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_direction(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	else
		return (0);
}

unsigned int	ft_color_converter(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

double	ft_degrees_to_radiants(double degrees)
{
	return (degrees * PI / 180);
}

unsigned int	ft_mlx_pixel_get(t_texture *data, int x, int y)
{
	char	*dst;

	dst = data->data + (y * data->size_line + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_render_pixel(t_texture img, int x, int y, int color)
{
	char	*dst;

	dst = img.data + (y * img.size_line + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}
