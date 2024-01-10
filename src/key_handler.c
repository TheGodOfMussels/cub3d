/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:38 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:38 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_wasd(t_game *p, int flag)
{
	double	playercos;
	double	playersin;

	playercos = cos(ft_degrees_to_radiants(p->angle)) * 0.2;
	playersin = sin(ft_degrees_to_radiants(p->angle)) * 0.2;
	if (flag == 0)
		ft_move_up(p, playercos, playersin);
	else if (flag == 1)
		ft_move_down(p, playercos, playersin);
	else if (flag == 2)
		ft_move_right(p, playercos, playersin);
	else if (flag == 3)
		ft_move_left(p, playercos, playersin);
}

int	ft_handlekeys(int ks, t_game *p)
{
	mlx_clear_window(p->mlx, p->win_ptr);
	if (ks == KEY_A)
		ft_move_wasd(p, 3);
	if (ks == KEY_D)
		ft_move_wasd(p, 2);
	if (ks == KEY_W)
		ft_move_wasd(p, 0);
	if (ks == KEY_S)
		ft_move_wasd(p, 1);
	if (ks == KEY_LEFT)
		p->angle -= 5;
	if (ks == KEY_RIGHT)
		p->angle += 5;
	if (ks == KEY_ESC)
		ft_close(p);
	ft_raycasting(p);
	mlx_put_image_to_window(p->mlx, p->win_ptr, p->img.ptr, 0, 0);
	return (0);
}
