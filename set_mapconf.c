/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:38:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/08 13:26:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*get_mapconf(char *file, char *lookfor, int i)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_puterror("this file is not exist.");
	while (get_next_line(fd, &line))
		if (!ft_strcmp(line, ""))
			continue ;
		else if (!ft_memcmp(lookfor, line, 1) &&
		(!ft_strcmp(lookfor, "C") || !ft_strcmp(lookfor, "F")))
			return (ft_split(++line, ',')[i]);
		else if (!ft_strcmp(ft_split(line, ' ')[0], lookfor))
		{
			if (ft_split(line, ' ')[2] != '\0')
			{
				ft_putstr(ft_split(line, ' ')[0]);
				ft_putstr("\n");
			}
			return (ft_split(line, ' ')[i]);
		}
	ft_puterror("you have to set your file with good data.");
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
	return (map);
}
