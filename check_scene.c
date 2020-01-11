/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:16:11 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/11 09:05:31 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*check_scene(char *scene)
{
	if (open(scene, O_RDONLY) < 0)
		ft_puterror("This map->path is not exist.");
	return (scene);
}

int		check_reso(char c, int res)
{
	if (res <= 0)
		ft_puterror("the resolution must have a positive value.");
	if (c == 'W')
		if (res > WIN_WIDTH)
			res = WIN_WIDTH;
	if (c == 'H')
		if (res > WIN_HEIGHT)
			res = WIN_HEIGHT;
	return (res);
}

void	check_walls(t_map map)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	end = 0;
	while (map.map[0][end])
		end++;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j] && !i)
			if (map.map[i][j++] != '1')
				ft_puterror("The map must be closed/surrounded by walls.");
		if (map.map[i][0] != '1' || map.map[i][end - 1] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
		i++;
	}
	j = 0;
	while (map.map[i - 1][j])
		if (map.map[i - 1][j++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
}

void	check_mapshape(t_map map)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j])
			if (map.map[i][j] != '1' && map.map[i][j] != '0' &&
			map.map[i][j] != '2' && map.map[i][j] != 'S' && map.map[i][j] != 'N'
			&& map.map[i][j] != 'W' && map.map[i][j] != 'E')
				ft_puterror("There is extra character in yout map");
			else if (map.map[i][j] == 'S' || map.map[i][j] == 'N'
			|| map.map[i][j] == 'W' || map.map[i][j] == 'E')
				player++;
	}
	if (!player)
		ft_puterror("There is no player on your map");
	if (player > 1)
		ft_puterror("you have multiple player on your map");
}
