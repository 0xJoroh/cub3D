/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/14 14:55:18 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		key_event(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == 13)
		map->player.axis.y -= 10;
	if (keycode == 1)
		map->player.axis.y += 10;
	if (keycode == 0)
		map->player.axis.x -= 10;
	if (keycode == 2)
		map->player.axis.x += 10;
	if (keycode == 53)
		quit(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	drawplayer(*map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
	map->img->img_ptr, 0, 0);
	return (0);
}

int		func(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	map->img->img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img->data = (int *)mlx_get_data_addr(map->img->img_ptr,
	&map->img->bpp, &map->img->size_l, &map->img->endian);
	map->axis.y = 0;
	sketchmap(*map);
	drawplayer(*map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
	map->img->img_ptr, 0, 0);
	mlx_hook(map->win_ptr, 17, 0, quit, map);
	mlx_hook(map->win_ptr, 2, 0, key_event, map);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
		ft_puterror("you have to pass a map in arguments");
	map = malloc(sizeof(t_map));
	map->img = malloc(sizeof(t_img));
	set_mapconf(argv[1], map);
	set_player(map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr,
	map->mapconf.r[0], map->mapconf.r[1], "Game");
	mlx_loop_hook(map->mlx_ptr, func, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
