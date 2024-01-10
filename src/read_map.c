/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:29:08 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/10 17:14:21 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_dup_map(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	len = ft_strlen(str) - 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		if (str[i] != '\n')
		{
			res[j++] = str[i];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	ft_set_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if ((ft_strchars_i(file[i], "10") != -1) && (ft_strchars_i(file[i],
					",") == -1))
			return (i);
		i++;
	}
	return (i);
}

int	ft_otherline_after(char **file, int i)
{
	int	j;

	j = i;
	while (file[j])
	{
		if (ft_strchars_i(file[j], "10NSEW") != -1)
			return (1);
		j++;
	}
	return (0);
}

int	ft_lenmap(char **file)
{
	int	i;
	int	len;

	i = ft_set_map(file);
	len = 0;
	while (file[i] && ft_otherline_after(file, i))
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_read_map(t_game *p, char **file)
{
	int	i;
	int	k;

	k = 0;
	i = ft_set_map(file);
	p->map = (char **)malloc(sizeof(char *) * (ft_lenmap(file) + 1));
	while (file[i] && ft_otherline_after(file, i))
		p->map[k++] = ft_dup_map(file[i++]);
	p->map[k] = NULL;
}
