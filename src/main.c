/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/24 16:17:59 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

int		main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
		ft_puterror("you have to pass at least two argument");
	setup(argv[1]);
	if (argc == 3)
		bmp(argv[2]);
	mlx_hook(t_map.win_ptr, 2, 0, key_press, (void*)0);
	mlx_hook(t_map.win_ptr, 3, 0, key_releas, (void*)0);
	mlx_hook(t_map.win_ptr, 17, 0, quit, (void*)0);
	mlx_loop_hook(t_map.mlx_ptr, loop_hook, (void*)0);
	mlx_loop(t_map.mlx_ptr);
	return (0);
}
