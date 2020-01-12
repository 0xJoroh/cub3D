/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketchmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:53:04 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/12 09:17:21 by mait-si-         ###   ########.fr       */
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
				map.img.data[y * WIN_WIDTH + x] = PLAYER;
			y++;
		}
		x++;
	}
}

t_player	set_player(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'N' || map.map[y][x] == 'S'
			|| map.map[y][x] == 'W' || map.map[y][x] == 'E')
			{
				map.player.axis.x = map.axis.x;
				map.player.axis.y = map.axis.y;
				map.player.vision = map.map[y][x];
			}
			map.axis.x += SIZE;
			x++;
		}
		map.axis.x = 0;
		map.axis.y += SIZE;
		y++;
	}
	return (map.player);
}

void		drawsquar(t_map map, int size)
{
	int		y;
	int		x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map.img.data[map.axis.y * WIN_WIDTH + map.axis.x] = WALL_COLOR;
			map.axis.x++;
			x++;
		}
		map.axis.y++;
		map.axis.x -= size;
		y++;
	}
}

void		sketchmap(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '1')
				drawsquar(map, SIZE);
			map.axis.x += SIZE;
			x++;
		}
		map.axis.x = 0;
		map.axis.y += SIZE;
		y++;
	}
	// drawplayer(map, 6);
}
