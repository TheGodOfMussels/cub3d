/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:10 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:11 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_c_param(int *param, char par, int flag)
{
	if (flag == 0)
	{
		param[0] = 0;
		param[1] = 0;
		param[2] = 0;
		param[3] = 0;
		param[4] = 0;
		param[5] = 0;
	}
	else
	{
		if (par == 'N')
			param[0]++;
		else if (par == 'S')
			param[1]++;
		else if (par == 'W')
			param[2]++;
		else if (par == 'E')
			param[3]++;
		else if (par == 'F')
			param[4]++;
		else if (par == 'C')
			param[5]++;
	}
}

int	ft_param_check(char **file)
{
	int	i;
	int	j;
	int	param[6];

	i = -1;
	ft_c_param(param, 'I', 0);
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (ft_strchr_i("FC", file[i][j]) != -1 || (ft_strchr_i("WENS",
						file[i][j]) != -1 && file[i][j + 1]
					&& ft_strchr_i("EAO", file[i][j + 1]) != -1))
				ft_c_param(param, file[i][j], 1);
		}
	}
	i = -1;
	while (++i < 6)
	{
		if (param[i] != 1)
			return (0);
	}
	return (1);
}

int	ft_check_color(t_colors color)
{
	if (color.r < 0 || color.r > 255)
		return (0);
	if (color.g < 0 || color.g > 255)
		return (0);
	if (color.b < 0 || color.b > 255)
		return (0);
	return (1);
}

int	ft_check_tex(char *path)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (!path)
		return (0);
	while (path[i])
	{
		if (path[i] == '.')
		{
			flag = 1;
			i++;
			if (ft_strcmp(path + i, "xpm"))
				return (0);
		}
		i++;
	}
	if (flag == 0)
		return (0);
	if (access(path, F_OK) == -1)
		return (0);
	return (1);
}

int	ft_check_tex_color(t_game *p)
{
	if (!ft_check_tex(p->no.path))
		return (0);
	if (!ft_check_tex(p->so.path))
		return (0);
	if (!ft_check_tex(p->we.path))
		return (0);
	if (!ft_check_tex(p->ea.path))
		return (0);
	if (!ft_check_color(p->color[0]))
		return (0);
	if (!ft_check_color(p->color[1]))
		return (0);
	return (1);
}
