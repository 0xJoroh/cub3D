/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:16:11 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/25 14:28:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

char	*check_scene(char *scene)
{
	int len;

	len = ft_strlen(scene);
	if ((t_map.fd = open(scene, O_RDONLY)) < 0 || scene[len - 3] != 'c'
	|| scene[len - 2] != 'u' || scene[len - 1] != 'b')
		ft_puterror("This path is not exist.");
	return (scene);
}

int		check_reso(char c, int res)
{
	if (res <= 0)
		ft_puterror("the resolution must be grater than 0.");
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

	i = 0;
	while (t_map.conf.grid[0][i])
		if (t_map.conf.grid[0][i++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.1");
	i = 0;
	while (++i < t_map.grid_height - 1)
	{
		j = 0;
		if (t_map.conf.grid[i][0] != '1' ||
		t_map.conf.grid[i][t_map.grid_width - 1] != '1')
			ft_puterror("The map must be closed/surrounded by walls.2");
	}
	j = 0;
	while (t_map.conf.grid[i][j])
		if (t_map.conf.grid[i][j++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.3");
}

void	check_grid(void)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (t_map.conf.grid[++i])
	{
		j = -1;
		while (t_map.conf.grid[i][++j])
			if (t_map.conf.grid[i][j] != '1' &&
			t_map.conf.grid[i][j] != '0' && t_map.conf.grid[i][j] != '2' &&
			t_map.conf.grid[i][j] != 'S' && t_map.conf.grid[i][j] != 'N'
			&& t_map.conf.grid[i][j] != 'W' && t_map.conf.grid[i][j] != 'E')
				ft_puterror("There is extra character in your map");
			else if (t_map.conf.grid[i][j] == 'S' ||
			t_map.conf.grid[i][j] == 'N' || t_map.conf.grid[i][j] == 'W' ||
			t_map.conf.grid[i][j] == 'E')
				player++;
	}
	if (player != 1)
		ft_puterror("you have to have just 1 player");
}
