/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/15 18:07:42 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

// int		mouse_event(int mouse)
// {
// 	ft_putnbr(mouse);
	//mouse_hook(mouse, , , (void*)0);
// 	exit(1);
// }

int		main(int argc, char *argv[])
{
	if (argc != 2)
		ft_puterror("you have to pass a map in arguments");
	setup(argv[1]);
	mlx_hook(t_map.win_ptr, 2, 0, key_press, (void*)0);
	mlx_hook(t_map.win_ptr, 3, 0, key_releas, (void*)0);
	mlx_hook(t_map.win_ptr, 17, 0, quit, (void*)0);
	// mlx_mouse_hook(t_map.win_ptr, mouse_event, (void*)0);
	mlx_loop_hook(t_map.mlx_ptr, key_event, (void*)0);
	mlx_loop(t_map.mlx_ptr);
	return (0);
}
