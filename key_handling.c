/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:34:39 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 15:54:21 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		key_event(t_map *map)
{
	float x;
	float y;

	if (map->player->angle == 360 || map->player->angle == -360)
		map->player->angle = 0;
	x = cos(map->player->angle * M_PI / 180) * 3 + map->player->axis.x;
	y = sin(map->player->angle * M_PI / 180) * 3 + map->player->axis.y;
	if (g_key.forward && map->grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		map->player->axis.x = x;
		map->player->axis.y = y;
	}
	x = -cos(map->player->angle * M_PI / 180) * 3 + map->player->axis.x;
	y = -sin(map->player->angle * M_PI / 180) * 3 + map->player->axis.y;
	if (g_key.backward && map->grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		map->player->axis.x = x;
		map->player->axis.y = y;
	}
	x = cos((map->player->angle - 90) * M_PI / 180) * 3 + map->player->axis.x;
	y = sin((map->player->angle - 90) * M_PI / 180) * 3 + map->player->axis.y;
	if (g_key.left && map->grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		map->player->axis.x = x;
		map->player->axis.y = y;
	}
	x = cos((map->player->angle + 90) * M_PI / 180) * 3 + map->player->axis.x;
	y = sin((map->player->angle + 90) * M_PI / 180) * 3 + map->player->axis.y;
	if (g_key.right && map->grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		map->player->axis.x = x;
		map->player->axis.y = y;
	}
	if (g_key.left_vision)
		map->player->angle -= 5;
	if (g_key.right_vision)
		map->player->angle += 5;
	if (g_key.quit)
		quit(map);
	if (g_key.left_vision || g_key.right_vision || g_key.right || g_key.left || g_key.forward || g_key.backward)
	{
		mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
		draw(map);
	}

	return (0);
}

int key_releas(int keycode)
{
	if (keycode == 13)
		g_key.forward = 0;
	if (keycode == 1)
		g_key.backward = 0;
	if (keycode == 0)
		g_key.left = 0;
	if (keycode == 2)
		g_key.right = 0;
	if (keycode == 123)
		g_key.left_vision = 0;
	if (keycode == 124)
		g_key.right_vision = 0;
	if (keycode == 53)
		g_key.quit = 0;
	return 0;
}

int		key_press(int keycode)
{
	if (keycode == 13)
		g_key.forward = 1;
	if (keycode == 1)
		g_key.backward = 1;
	if (keycode == 0)
		g_key.left = 1;
	if (keycode == 2)
		g_key.right = 1;
	if (keycode == 123)
		g_key.left_vision = 1;
	if (keycode == 124)
		g_key.right_vision = 1;
	if (keycode == 53)
		g_key.quit = 1;
	return 0;
}
