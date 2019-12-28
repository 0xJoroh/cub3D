/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:16:12 by mait-si-          #+#    #+#             */
/*   Updated: 2019/12/27 19:25:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		expose(t_map *map)
{
	(void)map;
	// freeing_memory(map);
	exit(1);
}

int		key_event(int keycode, t_map *map)
{
	// if (keycode == 126)

	// if (keycode == 125)

	// if (keycode == 124)

	// if (keycode == 123)

	if (keycode == 53)
		expose(&*map);
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
}

int		main(void)
{
	t_map	map;

	map = set_mapconf();
	// check_mapconf(map);
	map.mlx_ptr = mlx_init();
	map.win_ptr =
	mlx_new_window(map.mlx_ptr, map.mapconf.r[0], map.mapconf.r[1], "Cub3d");
	sketchmap(map);
	mlx_hook(map.win_ptr, 17, 0, expose, &map);
	mlx_hook(map.win_ptr, 2, 0, key_event, &map);
	mlx_loop(map.mlx_ptr);
	// ft_putstruct(map);
	return (0);
}
