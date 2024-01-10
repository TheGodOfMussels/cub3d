/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:29:14 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/10 17:13:26 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extension_check(char *path)
{
	int	len;

	len = ft_strlen(path) - 1;
	if (path[len] == 'b')
	{
		len--;
		if (path[len] == 'u')
		{
			len--;
			if (path[len] == 'c')
			{
				len--;
				if (path[len] == '.')
					return (1);
			}
		}
	}
	return (0);
}

int	ft_fileline_nb(char *path)
{
	int		n;
	int		fd;
	int		i;
	char	buff[1];

	n = 0;
	i = 1;
	fd = open(path, O_RDONLY);
	while (i != 0)
	{
		i = read(fd, buff, 1);
		if (buff[0] == '\n')
			n++;
	}
	close(fd);
	n++;
	return (n);
}

char	**ft_readfile(char *path)
{
	char	**file;
	int		i;
	int		fd;

	i = 0;
	if (!ft_extension_check(path))
		return (NULL);
	if (access(path, F_OK) == -1)
		return (NULL);
	file = (char **)malloc(sizeof(char *) * (ft_fileline_nb(path) + 1));
	fd = open(path, O_RDONLY);
	file[i] = get_next_line(fd);
	while (file[i])
	{
		i++;
		file[i] = get_next_line(fd);
	}
	return (file);
}
