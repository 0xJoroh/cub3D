/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:01:30 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/25 14:16:06 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

int		wall_collision(float x, float y)
{
	if (x > 0 && y > 0)
		if ((int)y / SIZE < t_map.grid_height && (int)x / SIZE < t_map.grid_width)
			return (t_map.conf.grid[(int)y / SIZE][(int)x / SIZE] == '1');
	return (1);
}

int		sprite_collision(float x, float y)
{
	if (x > 0 && y > 0)
		if ((int)y / SIZE < t_map.grid_height && (int)x / SIZE < t_map.grid_width)
			return (t_map.conf.grid[(int)y / SIZE][(int)x / SIZE] == '2');
	return (1);
}

void	textures_init2(void)
{
	if (!(t_map.texture.xpm_ptr[0] = mlx_xpm_file_to_image(t_map.mlx_ptr,
	t_map.conf.ea, &t_map.texture.width[0], &t_map.texture.height[0])))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.data[0] =
	(int *)mlx_get_data_addr(t_map.texture.xpm_ptr[0], &t_map.texture.bpp,
	&t_map.texture.size_l, &t_map.texture.endian)))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.xpm_ptr[1] = mlx_xpm_file_to_image(t_map.mlx_ptr,
	t_map.conf.we, &t_map.texture.width[1], &t_map.texture.height[1])))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.data[1] =
	(int *)mlx_get_data_addr(t_map.texture.xpm_ptr[1], &t_map.texture.bpp,
	&t_map.texture.size_l, &t_map.texture.endian)))
		ft_puterror("texture path is not exist");
}

void	textures_init(void)
{
	textures_init2();
	if (!(t_map.texture.xpm_ptr[2] = mlx_xpm_file_to_image(t_map.mlx_ptr,
	t_map.conf.so, &t_map.texture.width[2], &t_map.texture.height[2])))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.data[2] =
	(int *)mlx_get_data_addr(t_map.texture.xpm_ptr[2], &t_map.texture.bpp,
	&t_map.texture.size_l, &t_map.texture.endian)))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.xpm_ptr[3] = mlx_xpm_file_to_image(t_map.mlx_ptr,
	t_map.conf.no, &t_map.texture.width[3], &t_map.texture.height[3])))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.data[3] =
	(int *)mlx_get_data_addr(t_map.texture.xpm_ptr[3], &t_map.texture.bpp,
	&t_map.texture.size_l, &t_map.texture.endian)))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.xpm_ptr[4] = mlx_xpm_file_to_image(t_map.mlx_ptr,
	t_map.conf.s, &t_map.texture.width[4], &t_map.texture.height[4])))
		ft_puterror("texture path is not exist");
	if (!(t_map.texture.data[4] =
	(int *)mlx_get_data_addr(t_map.texture.xpm_ptr[4], &t_map.texture.bpp,
	&t_map.texture.size_l, &t_map.texture.endian)))
		ft_puterror("texture path is not exist");
}

int		get_player(int i, int j, int x, int y)
{
	if (t_map.conf.grid[i][j] == 'N' || t_map.conf.grid[i][j] == 'S'
	|| t_map.conf.grid[i][j] == 'W' || t_map.conf.grid[i][j] == 'E')
	{
		t_map.player.y = y + SIZE / 2;
		t_map.player.x = x + SIZE / 2;
		if (t_map.conf.grid[i][j] == 'N')
			t_map.ray.angle = 1.5 * M_PI;
		if (t_map.conf.grid[i][j] == 'E')
			t_map.ray.angle = 0;
		if (t_map.conf.grid[i][j] == 'S')
			t_map.ray.angle = M_PI * 0.5;
		if (t_map.conf.grid[i][j] == 'W')
			t_map.ray.angle = M_PI;
		return (1);
	}
	return (0);
}
