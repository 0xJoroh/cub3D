/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/23 02:52:14 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

t_sprite	**g_sprites;
int			g_sprite_texture;
double		*g_zbuffer;

int		main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
		ft_puterror("you have to pass at least two argument");
	g_sprites = ft_calloc(1, sizeof(t_sprite*));
	setup(argv[1]);
	if (argc == 3 && !ft_strcmp("––save", argv[2]))
		bmp(argv[2]);
	mlx_hook(g_map.win_ptr, 2, 0, key_press, (void*)0);
	mlx_hook(g_map.win_ptr, 3, 0, key_releas, (void*)0);
	mlx_hook(g_map.win_ptr, 17, 0, quit, (void*)0);
	mlx_loop_hook(g_map.mlx_ptr, loop_hook, (void*)0);
	mlx_loop(g_map.mlx_ptr);
	return (0);
}
