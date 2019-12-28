/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketchmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:53:04 by mait-si-          #+#    #+#             */
/*   Updated: 2019/12/27 18:26:52 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	drawcircle(t_map map, int r)
{
	int x;
	int y;

	x = map.axis.x - r;
	while (x < map.axis.x + r)
	{
		y = map.axis.y - r;
		while (y < map.axis.y + r)
		{
			if ((pow(x - map.axis.x, 2) + pow(y - map.axis.y, 2)) <= pow(r, 2))
				mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, PURPLE);
			y++;
		}
		x++;
	}
}

void	drawsquar(t_map map, int color, int size)
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

void	sketchmap(t_map map)
{
	int		fd;
	char	*line;

	map.axis.y = 0;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_memcmp(line, "1", 1))
			continue ;
		map.axis.x = 0;
		while (*line)
		{
			if (*line == '1')
				drawsquar(map, WALL, 55);
			if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
				drawcircle(map, 6);
			map.axis.x += 55;
			line++;
			while (*line == ' ')
				line++;
		}
		map.axis.y += 55;
	}
}
