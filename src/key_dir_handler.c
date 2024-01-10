/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dir_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:33 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:34 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_down(t_game *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x - playercos;
	newy = prg->spawn_y - playersin;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

void	ft_move_up(t_game *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x + playercos;
	newy = prg->spawn_y + playersin;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

void	ft_move_right(t_game *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x - playersin;
	newy = prg->spawn_y + playercos;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}

void	ft_move_left(t_game *prg, double playercos, double playersin)
{
	double	newx;
	double	newy;

	newx = prg->spawn_x + playersin;
	newy = prg->spawn_y - playercos;
	if (prg->map[(int)floor(newy)][(int)floor(newx)] == 48
		|| ft_is_direction(prg->map[(int)floor(newy)][(int)floor(newx)]) == 1)
	{
		prg->spawn_x = newx;
		prg->spawn_y = newy;
	}
}
