/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketchmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:53:04 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 10:10:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		drawplayer(t_map map, int r)
{
	int			x;
	int			y;

	x = map.player.axis.x - r;
	while (x < map.player.axis.x + r)
	{
		y = map.player.axis.y - r;
		while (y < map.player.axis.y + r)
		{
			if ((pow(x - map.player.axis.x, 2) + pow(y - map.player.axis.y, 2))
			<= pow(r, 2))
				mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, PLAYER);
			y++;
		}
		x++;
	}
}

void		drawsquar(t_map map, int color, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < size)
			mlx_pixel_put(map.mlx_ptr, map.win_ptr,
			map.axis.x++, map.axis.y, color);
		map.axis.y++;
		map.axis.x -= size;
		i++;
	}
}

t_player	set_player(t_map map)
{
	char		*line;
	int			fd;

	map.axis.y = 0;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_memcmp(line, "1", 1))
			continue ;
		map.axis.x = 0;
		while (*line++)
		{
			if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
			{
				map.player.axis.x = map.axis.x;
				map.player.axis.y = map.axis.y;
				map.player.vision = *line;
				return (map.player);
			}
			if (*line == '0' || *line == '1')
				map.axis.x += 55;
		}
		map.axis.y += 55;
	}
	return (map.player);
}

void		sketchmap(t_map *map)
{
	int		fd;
	char	*line;

	map->axis.y = 0;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		map->axis.x = 0;
		while (*line)
		{
			if (*line == '1')
				drawsquar(*map, WALL, 55);
			map->axis.x += 55;
			line++;
			while (*line == ' ')
				line++;
		}
		map->axis.y += 55;
	}
	drawplayer(*map, 6);
}
