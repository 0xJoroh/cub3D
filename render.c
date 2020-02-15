/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:55:09 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/15 15:36:46 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		walls(float x, float y, float height)
{
	float	i;
	float	factor;
	// float	t;

	i = 0;
	// t = 0;
	factor = (float)t_map.texture.height / height;
	// factor = (float)t_map.texture.height / height;
	while (i < height)
	{
		int color = t_map.texture.data[(int)(i * factor) % 64 * t_map.texture.width + (int)t_map.ray.x_offset % 64];
		render_px(x, i + y, color);
		i++;
	}
	// while (i < height)
	// {
	// 	int color = t_map.texture.data[(int)((int)t * t_map.ray.x_offset + t_map.texture.width)];
	// 	render_px(x, i + y, color);
	// 	i++;
	// 	t += factor;
	// }
}

void		render_view(void)
{
	int		i;
	float	wall_hight;
	float	angle;

	i = -1;
	angle = normalize_angle(t_map.ray.angle - FOV_ANGLE / 2);
	while (i++ < t_map.conf.r[0])
	{
		ray_init(angle);
		t_map.ray.distance = raycast(angle) * cos(angle - t_map.ray.angle);
		wall_hight = (SIZE / t_map.ray.distance) * (t_map.conf.r[0] / 2) / tan(FOV_ANGLE / 2);
		float start = (t_map.conf.r[1] / 2) - (wall_hight / 2) + t_map.key.up_angle;
		// ceiling(i, start, t_map.conf.c);
		walls(i, start, wall_hight);
		// flooor(i, (t_map.conf.r[1] / 2) + (wall_hight / 2) + t_map.key.up_angle, t_map.conf.f);
		angle += FOV_ANGLE / t_map.conf.r[0];
	}
}

void		draw()
{
	t_map.img.img_ptr = mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr, &t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
	t_map.texture.xpm_ptr = mlx_xpm_file_to_image(t_map.mlx_ptr, t_map.conf.ea, &t_map.texture.width, &t_map.texture.height);
	t_map.texture.data = (int *)mlx_get_data_addr(t_map.texture.xpm_ptr, &t_map.texture.bpp, &t_map.texture.size_l, &t_map.texture.endian);
	render_view();
	mlx_put_image_to_window(t_map.mlx_ptr, t_map.win_ptr, t_map.img.img_ptr, 0, 0);
}
