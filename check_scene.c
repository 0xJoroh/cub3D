/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:16:11 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/10 01:05:51 by mait-si-         ###   ########.fr       */
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

void	check_walls(void)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	end = 0;
	while (t_map.grid[0][end])
		end++;
	while (t_map.grid[i])
	{
		j = 0;
		while (t_map.grid[i][j] && !i)
			if (t_map.grid[i][j++] != '1')
				ft_puterror("The map must be closed/surrounded by walls.");
		if (t_map.grid[i][0] != '1' || t_map.grid[i][end - 1] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
		i++;
	}
	j = 0;
	while (t_map.grid[i - 1][j])
		if (t_map.grid[i - 1][j++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
}

void	check_grid(void)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (t_map.grid[++i])
	{
		j = -1;
		while (t_map.grid[i][++j])
			if (t_map.grid[i][j] != '1' &&
			t_map.grid[i][j] != '0' && t_map.grid[i][j] != '2' &&
			t_map.grid[i][j] != 'S' && t_map.grid[i][j] != 'N'
			&& t_map.grid[i][j] != 'W' && t_map.grid[i][j] != 'E')
				ft_puterror("There is extra character in your map");
			else if (t_map.grid[i][j] == 'S' || t_map.grid[i][j] == 'N'
			|| t_map.grid[i][j] == 'W' || t_map.grid[i][j] == 'E')
				player++;
	}
	if (player != 1)
		ft_puterror("you have to have just 1 player");
}
