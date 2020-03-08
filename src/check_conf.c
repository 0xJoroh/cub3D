/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:16:11 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/06 18:07:25 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

char		*check_scene(char *scene)
{
	int len;

	len = ft_strlen(scene);
	if ((t_map.fd = open(scene, O_RDONLY)) < 0 || scene[len - 3] != 'c'
	|| scene[len - 2] != 'u' || scene[len - 1] != 'b')
		ft_puterror("This path is not exist.");
	return (scene);
}

int			check_reso(char c, int res)
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

static int	check_character(char c, float x, float y)
{
	if (c != '1' && c != '0' && c != '2' && c != 'S' && c != 'N' &&
	c != 'W' && c != 'E')
		ft_puterror("There is extra character in your map");
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	if (c == '2')
	{
		x *= (SIZE / 2);
		y *= (SIZE / 2);
		add_sprite(g_sprites, new_sprite(x, y,
		distance(x, y, t_map.player.x, t_map.player.y)));
	}
	return (0);
}

void		check_conf(void)
{
	int		i;
	int		j;
	int		players;

	i = 0;
	players = 0;
	while (t_map.conf.grid[0][i])
		if (t_map.conf.grid[0][i++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.1");
	i = 0;
	while (++i < t_map.grid_height - 1)
	{
		if (t_map.conf.grid[i][0] != '1' ||
		t_map.conf.grid[i][t_map.grid_width - 1] != '1')
			ft_puterror("The map must be closed/surrounded by walls.2");
		j = -1;
		while (++j < t_map.grid_width - 1)
			players += check_character(t_map.conf.grid[i][j], (float)i, (float)j);
	}
	j = 0;
	if (players != 1)
		ft_puterror("you have to have just 1 player");
	while (t_map.conf.grid[i][j])
		if (t_map.conf.grid[i][j++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.3");
}
