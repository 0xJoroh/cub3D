/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/12 09:18:34 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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
	printf("- F\t\t:\t%lu\n", map.mapconf.f);
	printf("- C\t\t:\t%lu\n", map.mapconf.c);
	printf("- Vision\t\t:\t%c\n", map.player.vision);
	printf("- Player -XC\t\t:\t%d\n", map.player.axis.x);
	printf("- Player -Y\t\t:\t%d\n", map.player.axis.y);
	printf("- C\t\t:\t%lu\n", map.mapconf.c);
	printf("- C\t\t:\t%lu\n", map.mapconf.c);
	ft_print_words_tables(map.map);
}

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
}

int		key_event(int keycode, t_map map)
{
	if (keycode == 13)
		player_movment(&map, 'w');
	if (keycode == 1)
		player_movment(&map, 's');
	if (keycode == 0)
		player_movment(&map, 'a');
	if (keycode == 2)
		player_movment(&map, 'd');
	if (keycode == 53)
		quit(&map);
	// mlx_clear_window(map->mlx_ptr, map->win_ptr);
	// sketchmap(*map);
	// drawplayer(map, 6);
	ft_putstr("(");
	ft_putnbr(map.player.axis.x);
	ft_putstr(", ");
	ft_putnbr(map.player.axis.y);
	ft_putstr(")\n");
	return (0);
}

int		main(int argc, char *argv[])
{
	t_map			map;

	if (argc != 2)
		ft_puterror("you have to pass 1 argument");
	map = set_mapconf(argv[1]);
	map.mlx_ptr = mlx_init();
	map.win_ptr =
	mlx_new_window(map.mlx_ptr, map.mapconf.r[0], map.mapconf.r[1], "Cub3d");
	map.img.img_ptr = mlx_new_image(map.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map.img.data = (int *)mlx_get_data_addr(map.img.img_ptr, &map.img.bpp,
	&map.img.size_l, &map.img.endian);
	map.player = set_player(map);
	// sketchmap(map);
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, map.img.img_ptr, 0, 0);
	mlx_hook(map.win_ptr, 17, 0, quit, &map);
	mlx_hook(map.win_ptr, 2, 0, key_event, &map);
	mlx_loop(map.mlx_ptr);
	// ft_putstruct(map);
	return (0);
}
