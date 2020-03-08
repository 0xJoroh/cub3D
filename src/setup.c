/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:16:54 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 11:12:27 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static int				set_player(void)
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	i = 0;
	while (t_map.conf.grid[i])
	{
		j = 0;
		x = 0;
		while (t_map.conf.grid[i][j])
		{
			if (get_player(t_map.conf.grid[i][j], x, y))
				return (1);
			j++;
			x += SIZE;
		}
		y += SIZE;
		i++;
	}
	return (0);
}

void					setup(char *scene)
{
	t_map.mlx_ptr = mlx_init();
	t_map.scene = check_scene(scene);
	set_conf();
	set_player();
	check_conf();
	sort_sprite(g_sprites);
	textures_init();
	t_map.win_ptr = mlx_new_window(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1], "The Game");
	draw();
}
