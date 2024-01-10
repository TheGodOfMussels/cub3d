/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:18 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/10 17:13:55 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_save_val(char **file, char *to_find)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	while (file[++i])
	{
		j = 0;
		while (ft_isspace(file[i][j]))
			j++;
		if (to_find[0] == file[i][j])
		{
			j++;
			if (to_find[1] == file[i][j])
			{
				j++;
				while (ft_isspace(file[i][j]))
					j++;
				res = ft_strdup_special(file[i] + j);
				return (res);
			}
		}
	}
	return (NULL);
}

t_colors	ft_save_single_color(char *str)
{
	t_colors	color;
	char		**res;
	char		*pars;
	int			i;

	pars = ft_strdup_special(str);
	res = ft_split(pars, ',');
	i = 0;
	while (res[i])
	{
		if (i == 0)
			color.r = ft_atoi_special(res[i]);
		else if (i == 1)
			color.g = ft_atoi_special(res[i]);
		else if (i == 2)
			color.b = ft_atoi_special(res[i]);
		i++;
	}
	free(pars);
	ft_free_matrix(&res);
	if (i != 3)
		ft_color_err(&color);
	return (color);
}

t_colors	ft_save_color(char **file, char *key_wd)
{
	t_colors	color;
	int			i;
	int			k;

	i = 0;
	color.b = -1;
	color.g = -1;
	color.r = -1;
	while (file[i])
	{
		k = 0;
		while (ft_isspace(file[i][k]))
			k++;
		if (key_wd[0] == file[i][k])
		{
			k++;
			while (ft_isspace(file[i][k]))
				k++;
			color = ft_save_single_color(file[i] + k);
			return (color);
		}
		i++;
	}
	return (color);
}

void	ft_read_tex_color(t_game *p, char **file, int i)
{
	if (i == 0)
		p->no.path = ft_save_val(file, "NO");
	else if (i == 1)
		p->so.path = ft_save_val(file, "SO");
	else if (i == 2)
		p->we.path = ft_save_val(file, "WE");
	else if (i == 3)
		p->ea.path = ft_save_val(file, "EA");
	else if (i == 4)
		p->color[0] = ft_save_color(file, "F");
	else if (i == 5)
		p->color[1] = ft_save_color(file, "C");
}

int	ft_read_fields(t_game *p, char **file)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_read_tex_color(p, file, i);
		i++;
	}
	if (!ft_param_check(file))
		return (0);
	if (!ft_check_tex_color(p))
		return (0);
	ft_read_map(p, file);
	return (1);
}
