/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:57 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:57 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_charset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_horizontal(char **map, int idx, int k)
{
	int	x;

	x = k;
	if (k == 0 || !map[idx][k + 1])
		return (0);
	while (map[idx][x] && map[idx][x] != ' ')
	{
		if (map[idx][x] == '1')
			return (1);
		x++;
	}
	if (map[idx][x] && map[idx][x] == ' ')
		return (0);
	x = k;
	while (map[idx][x] && x >= 0 && map[idx][x] != ' ')
	{
		if (map[idx][x] == '1')
			return (1);
		x--;
	}
	return (0);
}

int	ft_check_vertical(char **map, int idx, int j)
{
	int	k;

	k = idx;
	if (idx == 0 || !map[idx + 1])
		return (0);
	while (map[k] && k >= 0)
	{
		if (map[k][j] == '1')
			return (1);
		k++;
	}
	k = idx;
	while (map[k] && k >= 0)
	{
		if (map[k][j] == '1')
			return (1);
		k--;
	}
	return (0);
}
