/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:23 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:23 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_path(t_game *p)
{
	free(p->no.path);
	free(p->so.path);
	free(p->we.path);
	free(p->ea.path);
}

int	ft_close(t_game *p)
{
	mlx_destroy_image(p->mlx, p->no.ptr);
	mlx_destroy_image(p->mlx, p->so.ptr);
	mlx_destroy_image(p->mlx, p->ea.ptr);
	mlx_destroy_image(p->mlx, p->we.ptr);
	mlx_destroy_image(p->mlx, p->img.ptr);
	mlx_destroy_window(p->mlx, p->win_ptr);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	ft_free_path(p);
	ft_free_matrix(&p->map);
	exit(0);
	return (0);
}
