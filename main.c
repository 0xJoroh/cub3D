/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/06 12:15:33 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		key_event(t_map *map)
{
	if (map->player->angle == 360 || map->player->angle == -360)
		map->player->angle = 0;
	if (g_key.forward)
	{
		map->player->axis.x = cos(map->player->angle * M_PI / 180) * 7 + map->player->axis.x;
		map->player->axis.y = sin(map->player->angle * M_PI / 180) * 7 + map->player->axis.y;
	}
	if (g_key.backward)
	{
		map->player->axis.x = -cos(map->player->angle * M_PI / 180) * 7 + map->player->axis.x;
		map->player->axis.y = -sin(map->player->angle * M_PI / 180) * 7 + map->player->axis.y;
	}
	if (g_key.left)
	{
		map->player->axis.x = cos((map->player->angle - 90) * M_PI / 180) * 7 + map->player->axis.x;
		map->player->axis.y = sin((map->player->angle - 90) * M_PI / 180) * 7 + map->player->axis.y;
	}
	if (g_key.right)
	{
		map->player->axis.x = cos((map->player->angle + 90) * M_PI / 180) * 7 + map->player->axis.x;
		map->player->axis.y = sin((map->player->angle + 90) * M_PI / 180) * 7 + map->player->axis.y;
	}
	if (g_key.left_vision)
		map->player->angle += 10;
	if (g_key.right_vision)
		map->player->angle -= 10;
	if (g_key.quit)
		quit(map);
	sketchmap(map);
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
	if (keycode == 124)
		g_key.left_vision = 0;
	if (keycode == 123)
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
	if (keycode == 124)
		g_key.left_vision = 1;
	if (keycode == 123)
		g_key.right_vision = 1;
	if (keycode == 53)
		g_key.quit = 1;
	return 0;
}

int		main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
		ft_puterror("you have to pass a map in arguments");
	map = ft_calloc(1, sizeof(t_map));
	map->img = ft_calloc(1, sizeof(t_img));
	map->axis = ft_calloc(1, sizeof(t_axis));
	map->mapconf = ft_calloc(1, sizeof(t_mapconf));
	map->player = ft_calloc(1, sizeof(t_player));
	map_init(argv[1], map);
	sketchmap(map);
	mlx_hook(map->win_ptr, 2, 0, key_press, (void*)0);
	mlx_hook(map->win_ptr, 3, 0, key_releas, (void*)0);
	mlx_hook(map->win_ptr, 17, 0, quit, map);
	mlx_loop_hook(map->mlx_ptr, key_event, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
