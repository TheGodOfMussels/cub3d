/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:51 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:51 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_zero_check(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == '0')
			{
				if (!ft_check_vertical(map, i, k))
					return (0);
				if (!ft_check_horizontal(map, i, k))
					return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_single_check(char **map)
{
	int	i;
	int	k;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		k = -1;
		while (map[i][++k])
		{
			if (ft_strchr_i("NSEW", map[i][k]) != -1 && flag == 0)
				flag = 1;
			else if (ft_strchr_i("NSEW", map[i][k]) != -1 && flag == 1)
				return (1);
		}
	}
	return (0);
}

int	ft_start_map_check(char **map)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	if (ft_single_check(map))
		return (0);
	while (map[i])
	{
		if (ft_strchars_i(map[i], "NSEW") != -1)
		{
			flag = 1;
			k = ft_strchars_i(map[i], "NSEW");
			if (i == 0 || !map[i + 1] || k == 0 || !map[i][k + 1])
				return (0);
		}
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	ft_map_checker(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchars_i(map[i], "10NSEW") == -1)
			return (0);
		if (!ft_check_charset(map[i]))
			return (0);
		i++;
	}
	if (!ft_start_map_check(map))
		return (0);
	if (!ft_zero_check(map))
		return (0);
	return (1);
}
