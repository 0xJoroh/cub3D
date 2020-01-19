/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketchmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:53:04 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/18 18:30:38 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		drawplayer(t_map *map)
{
	int			x;
	int			y;

	x = map->player.axis.x - 6;
	while (x < map->player.axis.x + 6)
	{
		y = map->player.axis.y - 6;
		while (y < map->player.axis.y + 6)
		{

			if ((pow(x - map->player.axis.x, 2) + pow(y - map->player.axis.y, 2)) <= pow(6, 2))
				map->img->data[y * WIN_WIDTH + x] = PLAYER;
			y++;
		}
		x++;
	}
}

void		drawsquar(t_map map)
{
	int		y;
	int		x;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			map.img->data[map.axis.y * WIN_WIDTH + map.axis.x++] = WALL_COLOR;
		map.axis.y++;
		map.axis.x -= SIZE;
	}
}

void		sketchmap(t_map map)
{
	while (*map.map)
	{
		while (**map.map)
		{
			if (**map.map == '1')
				drawsquar(map);
			map.axis.x += SIZE;
			(*map.map)++;
		}
		map.axis.x = 0;
		map.axis.y += SIZE;
		map.map++;
	}
}
