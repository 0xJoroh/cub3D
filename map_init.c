/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:40:26 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/06 12:45:54 by mait-si-         ###   ########.fr       */
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

void		set_mapconf(char *scene, t_mapconf *conf)
{
	conf->r[0] = check_reso('W', ft_atoi(get_mapconf(scene, "R", 1)));
	conf->r[1] = check_reso('H', ft_atoi(get_mapconf(scene, "R", 2)));
	conf->no = get_mapconf(scene, "NO", 1);
	conf->so = get_mapconf(scene, "SO", 1);
	conf->we = get_mapconf(scene, "WE", 1);
	conf->ea = get_mapconf(scene, "EA", 1);
	conf->s = get_mapconf(scene, "S", 1);
	conf->f = get_color(
	ft_atoi(get_mapconf(scene, "F", 0)),
	ft_atoi(get_mapconf(scene, "F", 1)),
	ft_atoi(get_mapconf(scene, "F", 2)));
	conf->c = get_color(
	ft_atoi(get_mapconf(scene, "C", 0)),
	ft_atoi(get_mapconf(scene, "C", 1)),
	ft_atoi(get_mapconf(scene, "C", 2)));
}

int		set_player(t_map *map)
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		x = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
			{
				map->player->axis.y = y + SIZE / 2;
				map->player->axis.x = x + SIZE / 2;
				map->player->vision = map->map[i][j];
				return (1);
			}
			j++;
			x += SIZE;
		}
		y += SIZE;
		i++;
	}
	return (0);
}

void			map_init(char *scene, t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->scene = check_scene(scene);
	set_mapconf(scene, map->mapconf);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->mapconf->r[0], map->mapconf->r[1], "Game");
	set_mapshape(map);
	set_player(map);
}
