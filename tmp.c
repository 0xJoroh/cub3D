/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:55:09 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/10 01:14:23 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		render_view(void)
{
	int		i;
	float	wall_hight;
	float	angle;

	i = -1;
	angle = normalize_angle(t_map.ray.angle - FOV_ANGLE / 2);
	while (i++ < t_map.conf.r[0])
	{
		ray_init(angle);
		t_map.ray.distance = raycast(angle) * cos(angle - t_map.ray.angle);
		wall_hight = (SIZE / t_map.ray.distance) *
		(t_map.conf.r[0] / 2) / tan(FOV_ANGLE / 2);
		ceiling(i, 0, 1, (t_map.conf.r[1] / 2) - (wall_hight / 2));
		walls(i, (t_map.conf.r[1] / 2) - (wall_hight / 2), 1, wall_hight);
		flooor(i, (t_map.conf.r[1] / 2) + (wall_hight / 2), 1);
		//Mini Map
		// for (int i = 0 ; i < t_map.ray.distance; i++)
		// {
		// 	float x = cos(angle) * i + t_map.player.x;
		// 	float y = sin(angle) * i + t_map.player.y;
		// 	render_px(x, y, PLAYER);
		// }
		angle += FOV_ANGLE / t_map.conf.r[0];
	}
}

void		player()
{
	int x = t_map.player.x - 6;
	while (x < t_map.player.x + 6)
	{
		int y = t_map.player.y - 6;
		while (y < t_map.player.y + 6)
		{
			if ((pow(x - t_map.player.x, 2) + pow(y - t_map.player.y, 2)) <= pow(6, 2))
				render_px(x, y, PLAYER);
			y++;
		}
		x++;
	}
}

void		squar()
{
	int		y;
	int		x;

	y = t_map.y - 1;

	while (++y < SIZE + t_map.y)
	{
		x = t_map.x - 1;
		while (++x < SIZE + t_map.x)
			render_px(x, y, WALL_COLOR);
	}
}

void		map()
{
	t_map.y = 0;
	for (int i = 0 ; t_map.grid[i] ; i++)
	{
		for (int j = 0; t_map.grid[i][j]; j++)
		{
			if (t_map.grid[i][j] == '1')
				squar();
			t_map.x += SIZE;
		}
		t_map.x = 0;
		t_map.y += SIZE;
	}
}


void		draw()
{
	t_map.img.img_ptr =
	mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr,
	&t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
	// map();
	render_view();
	// player();
	mlx_put_image_to_window(t_map.mlx_ptr,
	t_map.win_ptr, t_map.img.img_ptr, 0, 0);
}
