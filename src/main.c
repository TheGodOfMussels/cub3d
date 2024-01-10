/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:43 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:43 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_n_ac(int ac)
{
	if (ac < 2)
		ft_printf("Error: too few arguments!\n");
	else
		ft_printf("Error: too many arguments!\n");
	return (0);
}

void	ft_file_read_check(char **av, t_game *p)
{
	char	**file;

	file = ft_readfile(av[1]);
	if (!file)
	{
		ft_printf("Error: file %s not valid!\n", av[1]);
		p->err = 3;
		return ;
	}
	if (!ft_read_fields(p, file))
	{
		ft_free_matrix(&file);
		ft_printf("Error: invalid map and/or texture!\n");
		p->err = 2;
		return ;
	}
	if (!ft_map_checker(p->map))
	{
		ft_free_matrix(&file);
		ft_printf("Error: invalid map and/or texture!\n");
		p->err = 0;
		return ;
	}
	p->err = 1;
	ft_free_matrix(&file);
}

void	ft_game_set(t_game *p)
{
	ft_struct_setup(p);
	ft_spawn(p);
	ft_create_window(p);
	ft_raycasting(p);
	mlx_put_image_to_window(p->mlx, p->win_ptr, p->img.ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	p;

	if (ac != 2)
	{
		ft_error_n_ac(ac);
		return (0);
	}
	ft_file_read_check(av, &p);
	if (p.err != 1)
	{
		if (p.err != 3)
			ft_free_path(&p);
		if (p.err == 0)
			ft_free_matrix(&p.map);
		return (0);
	}
	ft_game_set(&p);
	mlx_hook(p.win_ptr, 2, 1L << 0, ft_handlekeys, &p);
	mlx_hook(p.win_ptr, 17, 0, ft_close, &p);
	mlx_loop(p.mlx);
}
