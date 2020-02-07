/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 16:45:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"


int		main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
		ft_puterror("you have to pass a map in arguments");
	map = ft_calloc(1, sizeof(t_map));
	map->img = ft_calloc(1, sizeof(t_img));
	map->axis = ft_calloc(1, sizeof(t_axis));
	map->conf = ft_calloc(1, sizeof(t_conf));
	map->player = ft_calloc(1, sizeof(t_player));
	setup(argv[1], map);
	mlx_hook(map->win_ptr, 2, 0, key_press, (void*)0);
	mlx_hook(map->win_ptr, 3, 0, key_releas, (void*)0);
	mlx_hook(map->win_ptr, 17, 0, quit, map);
	mlx_loop_hook(map->mlx_ptr, key_event, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
