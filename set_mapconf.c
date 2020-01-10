/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:38:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 10:16:48 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

// int		valid(char *str)
// {
// 	if (*str == 'R' || !ft_strcmp(str, "NO") || !ft_strcmp(str, "SO")
// 	|| !ft_strcmp(str, "WE") || !ft_strcmp(str, "EA") || *str == 'S' ||
// 	*str == 'F' || *str == 'C' || *str == '1')
// 		return (1);
// 	return (0);
// }

char	**get_mapshape(char *file)
{
	int		fd;
	char	*line;
	int		height;
	int		width;

	height = 0;
	width = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("This file is not exist.");
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		while (*line && width == 1)
		{
			if (*line == '1')
				height++;
			line++;
			while (*line == ' ')
				line++;
		}
		width++;
	}
	ft_putnbr(height);
	ft_putstr(", ");
	ft_putnbr(width);
	exit(1);
	return (ft_split(line, '\n'));
}

char	*get_mapconf(char *file, char *lookfor, int i)
{
	char	*line;
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("This file is not exist.");
	while (get_next_line(fd, &line))
		if (!ft_strcmp(line, "") || *line == '\n')
			continue ;
		else if (!ft_strcmp(lookfor, ft_split(line, ' ')[0]))
			if (*lookfor == 'C' || *lookfor == 'F')
				if (ft_tablen(ft_split(line, ' ')) != 2 ||
				ft_tablen(ft_split(++line, ',')) != 3)
					ft_puterror("Fix F or C data");
				else
					return (ft_split(line, ',')[i]);
			else if (*line == 'R' && ft_tablen(ft_split(line, ' ')) != 3)
				ft_puterror("Fix the resolution data");
			else if (*line != 'R' && ft_tablen(ft_split(line, ' ')) != 2)
				ft_puterror("you have to fix your texture path");
			else
				return (ft_split(line, ' ')[i]);
		else
			continue ;
	ft_puterror("you have to fix your file.");
	exit(-1);
}

t_map	set_mapconf(char *file)
{
	t_map	map;

	map.mlx_ptr = NULL;
	map.win_ptr = NULL;
	map.axis.x = 0;
	map.axis.y = 0;
	map.mapconf.r[0] = ft_atoi(get_mapconf(file, "R", 1));
	map.mapconf.r[1] = ft_atoi(get_mapconf(file, "R", 2));
	map.mapconf.no = get_mapconf(file, "NO", 1);
	map.mapconf.so = get_mapconf(file, "SO", 1);
	map.mapconf.we = get_mapconf(file, "WE", 1);
	map.mapconf.ea = get_mapconf(file, "EA", 1);
	map.mapconf.s = get_mapconf(file, "S", 1);
	map.mapconf.f[0] = ft_atoi(get_mapconf(file, "F", 0));
	map.mapconf.f[1] = ft_atoi(get_mapconf(file, "F", 1));
	map.mapconf.f[2] = ft_atoi(get_mapconf(file, "F", 2));
	map.mapconf.c[0] = ft_atoi(get_mapconf(file, "C", 0));
	map.mapconf.c[1] = ft_atoi(get_mapconf(file, "C", 1));
	map.mapconf.c[2] = ft_atoi(get_mapconf(file, "C", 2));
	map.map = get_mapshape(file);
	return (map);
}
