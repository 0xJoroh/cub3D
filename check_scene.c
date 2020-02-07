/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:16:11 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 17:04:12 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*check_scene(char *scene)
{
	int len;

	len = ft_strlen(scene);
	if (open(scene, O_RDONLY) < 0 || scene[len - 3] != 'c'
	|| scene[len - 2] != 'u' || scene[len - 1] != 'b')
		ft_puterror("This path is not exist.");
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
	while (map.grid[0][end])
		end++;
	while (map.grid[i])
	{
		j = 0;
		while (map.grid[i][j] && !i)
			if (map.grid[i][j++] != '1')
				ft_puterror("The map must be closed/surrounded by walls.");
		if (map.grid[i][0] != '1' || map.grid[i][end - 1] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
		i++;
	}
	j = 0;
	while (map.grid[i - 1][j])
		if (map.grid[i - 1][j++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
}

void	check_grid(t_map map)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (map.grid[++i])
	{
		j = -1;
		while (map.grid[i][++j])
			if (map.grid[i][j] != '1' && map.grid[i][j] != '0' &&
			map.grid[i][j] != '2' && map.grid[i][j] != 'S' && map.grid[i][j] != 'N'
			&& map.grid[i][j] != 'W' && map.grid[i][j] != 'E')
				ft_puterror("There is extra character in your map");
			else if (map.grid[i][j] == 'S' || map.grid[i][j] == 'N'
			|| map.grid[i][j] == 'W' || map.grid[i][j] == 'E')
				player++;
	}
	if (player != 1)
		ft_puterror("you have to have just 1 player");
}
