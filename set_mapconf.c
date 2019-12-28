/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:38:33 by mait-si-          #+#    #+#             */
/*   Updated: 2019/12/27 18:25:52 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*get_mapconf(char *lookfor, int i)
{
	char	*line;
	int		fd;

	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		exit(1);
	while (get_next_line(fd, &line))
		if (!ft_strcmp(line, ""))
			continue ;
		else if (!ft_memcmp(lookfor, line, 1) &&
		(!ft_strcmp(lookfor, "C") || !ft_strcmp(lookfor, "F")))
			return (ft_split(++line, ',')[i]);
		else if (!ft_strcmp(ft_split(line, ' ')[0], lookfor))
			return (ft_split(line, ' ')[i]);
	exit(1);
}

t_map	set_mapconf(void)
{
	t_map	map;

	map.mlx_ptr = NULL;
	map.win_ptr = NULL;
	map.axis.x = 0;
	map.axis.y = 0;
	map.mapconf.r[0] = ft_atoi(get_mapconf("R", 1));
	map.mapconf.r[1] = ft_atoi(get_mapconf("R", 2));
	map.mapconf.no = get_mapconf("NO", 1);
	map.mapconf.so = get_mapconf("SO", 1);
	map.mapconf.we = get_mapconf("WE", 1);
	map.mapconf.ea = get_mapconf("EA", 1);
	map.mapconf.s = get_mapconf("S", 1);
	map.mapconf.f[0] = ft_atoi(get_mapconf("F", 0));
	map.mapconf.f[1] = ft_atoi(get_mapconf("F", 1));
	map.mapconf.f[2] = ft_atoi(get_mapconf("F", 2));
	map.mapconf.c[0] = ft_atoi(get_mapconf("C", 0));
	map.mapconf.c[1] = ft_atoi(get_mapconf("C", 1));
	map.mapconf.c[2] = ft_atoi(get_mapconf("C", 2));
	return (map);
}
