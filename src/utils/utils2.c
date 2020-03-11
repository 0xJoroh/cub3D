/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:01:30 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/11 14:04:38 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

int		collision(float x, float y, char c)
{
	if (x > 0 && y > 0)
		if ((int)y / SIZE < g_map.grid_height && (int)x / SIZE < g_map.grid_width)
			return (g_map.conf.grid[(int)y / SIZE][(int)x / SIZE] == c);
	return (1);
}

void	textures_init2(void)
{
	if (!(g_map.texture.xpm_ptr[0] = mlx_xpm_file_to_image(g_map.mlx_ptr,
	g_map.conf.ea, &g_map.texture.width[0], &g_map.texture.height[0])))
		ft_puterror("EA texture path is not exist");
	if (!(g_map.texture.data[0] =
	(int *)mlx_get_data_addr(g_map.texture.xpm_ptr[0], &g_map.texture.bpp,
	&g_map.texture.size_l, &g_map.texture.endian)))
		ft_puterror("EA texture path is not exist");
	if (!(g_map.texture.xpm_ptr[1] = mlx_xpm_file_to_image(g_map.mlx_ptr,
	g_map.conf.we, &g_map.texture.width[1], &g_map.texture.height[1])))
		ft_puterror("WE texture path is not exist");
	if (!(g_map.texture.data[1] =
	(int *)mlx_get_data_addr(g_map.texture.xpm_ptr[1], &g_map.texture.bpp,
	&g_map.texture.size_l, &g_map.texture.endian)))
		ft_puterror("WE texture path is not exist");
}

void	textures_init(void)
{
	textures_init2();
	if (!(g_map.texture.xpm_ptr[2] = mlx_xpm_file_to_image(g_map.mlx_ptr,
	g_map.conf.so, &g_map.texture.width[2], &g_map.texture.height[2])))
		ft_puterror("SO texture path is not exist");
	if (!(g_map.texture.data[2] =
	(int *)mlx_get_data_addr(g_map.texture.xpm_ptr[2], &g_map.texture.bpp,
	&g_map.texture.size_l, &g_map.texture.endian)))
		ft_puterror("SO texture path is not exist");
	if (!(g_map.texture.xpm_ptr[3] = mlx_xpm_file_to_image(g_map.mlx_ptr,
	g_map.conf.no, &g_map.texture.width[3], &g_map.texture.height[3])))
		ft_puterror("NO texture path is not exist");
	if (!(g_map.texture.data[3] =
	(int *)mlx_get_data_addr(g_map.texture.xpm_ptr[3], &g_map.texture.bpp,
	&g_map.texture.size_l, &g_map.texture.endian)))
		ft_puterror("NO texture path is not exist");
	if (!(g_map.texture.xpm_ptr[4] = mlx_xpm_file_to_image(g_map.mlx_ptr,
	g_map.conf.s, &g_map.texture.width[4], &g_map.texture.height[4])))
		ft_puterror("Sprite texture path is not exist");
	if (!(g_map.texture.data[4] =
	(int *)mlx_get_data_addr(g_map.texture.xpm_ptr[4], &g_map.texture.bpp,
	&g_map.texture.size_l, &g_map.texture.endian)))
		ft_puterror("Sprite texture path is not exist");
}

int		get_player(char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		g_map.player.y = y + SIZE / 2;
		g_map.player.x = x + SIZE / 2;
		if (c == 'N')
			g_map.ray.angle = 1.5 * M_PI;
		if (c == 'E')
			g_map.ray.angle = 0.01;
		if (c == 'S')
			g_map.ray.angle = M_PI * 0.5;
		if (c == 'W')
			g_map.ray.angle = M_PI;
		return (1);
	}
	return (0);
}
