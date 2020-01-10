/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 14:05:36 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	player_movment(t_map *map, char way)
{
	if (way == 'w')
		map->player.axis.y -= 10;
	if (way == 's')
		map->player.axis.y += 10;
	if (way == 'a')
		map->player.axis.x -= 10;
	if (way == 'd')
		map->player.axis.x += 10;
	sketchmap(map);
}

int		key_event(int keycode, t_map *map)
{
	if (keycode == 13)
		player_movment(&*map, 'w');
	if (keycode == 1)
		player_movment(&*map, 's');
	if (keycode == 0)
		player_movment(&*map, 'a');
	if (keycode == 2)
		player_movment(&*map, 'd');
	if (keycode == 53)
		quit(&*map);
	return (0);
}

void	ft_putstruct(t_map map)
{
	printf("- X\t\t:\t%d\n", map.axis.x);
	printf("- Y\t\t:\t%d\n", map.axis.y);
	printf("- Resolution-X\t:\t%d\n", map.mapconf.r[0]);
	printf("- Resolution-Y\t:\t%d\n", map.mapconf.r[1]);
	printf("- NO\t\t:\t%s\n", map.mapconf.no);
	printf("- SO\t\t:\t%s\n", map.mapconf.so);
	printf("- WE\t\t:\t%s\n", map.mapconf.we);
	printf("- EA\t\t:\t%s\n", map.mapconf.ea);
	printf("- S\t\t:\t%s\n", map.mapconf.s);
	printf("- F\t\t:\t(%d, %d, %d)\n",
	map.mapconf.f[0], map.mapconf.f[1], map.mapconf.f[2]);
	printf("- C\t\t:\t(%d, %d, %d)\n",
	map.mapconf.c[0], map.mapconf.c[1], map.mapconf.c[2]);
	ft_print_words_tables(map.map);
}

int		main(int argc, char *argv[])
{
	t_map			map;

	if (argc != 2)
		ft_puterror("you have to pass 1 argument");
	map = set_mapconf(argv[1]);
	map = check_mapconf(map);
	// map.mlx_ptr = mlx_init();
	// map.win_ptr =
	// mlx_new_window(map.mlx_ptr, map.mapconf.r[0], map.mapconf.r[1], "Cub3d");
	// sketchmap(&map);
	// map.player = set_player(map);
	// drawplayer(map, 6);
	// mlx_hook(map.win_ptr, 17, 0, quit, &map);
	// mlx_hook(map.win_ptr, 2, 0, key_event, &map);
	// mlx_loop(map.mlx_ptr);
	ft_putstruct(map);
	return (0);
}
