/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:38:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/14 10:57:31 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

unsigned long	get_color(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_puterror("the Colors must have a value between 0 and 255.");
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

char			*get_mapconf(char *scene, char *lookfor, int i)
{
	char	*line;
	int		fd;

	if ((fd = open(scene, O_RDONLY)) < 0)
		ft_puterror("This scene is not exist.");
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
	ft_puterror("you have to fix your scene.");
	exit(-1);
}

void			set_mapconf(char *scene,t_map *map)
{
	map->scene = check_scene(scene);
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
	map->axis.x = 0;
	map->axis.y = 0;
	map->mapconf.r[0] = check_reso('W', ft_atoi(get_mapconf(scene, "R", 1)));
	map->mapconf.r[1] = check_reso('H', ft_atoi(get_mapconf(scene, "R", 2)));
	map->mapconf.no = get_mapconf(scene, "NO", 1);
	map->mapconf.so = get_mapconf(scene, "SO", 1);
	map->mapconf.we = get_mapconf(scene, "WE", 1);
	map->mapconf.ea = get_mapconf(scene, "EA", 1);
	map->mapconf.s = get_mapconf(scene, "S", 1);
	map->mapconf.f = get_color(
	ft_atoi(get_mapconf(scene, "F", 0)),
	ft_atoi(get_mapconf(scene, "F", 1)),
	ft_atoi(get_mapconf(scene, "F", 2)));
	map->mapconf.c = get_color(
	ft_atoi(get_mapconf(scene, "C", 0)),
	ft_atoi(get_mapconf(scene, "C", 1)),
	ft_atoi(get_mapconf(scene, "C", 2)));
	set_mapshape(map);
}
