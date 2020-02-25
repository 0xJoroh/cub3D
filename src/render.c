/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:55:09 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/25 13:25:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static int	get_texture_num(void)
{
	if (t_map.ray.wall_hit && t_map.ray.is_left)
		return (1);
	if (t_map.ray.wall_hit && t_map.ray.is_right)
		return (0);
	if (!t_map.ray.wall_hit && t_map.ray.is_up)
		return (3);
	if (!t_map.ray.wall_hit && t_map.ray.is_down)
		return (2);
	return (0);
}

void		render_view(void)
{
	int		i;
	float	wall_hight;
	float	angle;
	float	start;

	i = -1;
	angle = normalize_angle(t_map.ray.angle - FOV_ANGLE / 2);
	while (i++ < t_map.conf.r[0])
	{
		ray_init(angle);
		t_map.ray.distance = raycast(angle) * cos(angle - t_map.ray.angle);
		wall_hight = (SIZE / t_map.ray.distance) * \
		(t_map.conf.r[0] / 2) / tan(FOV_ANGLE / 2);
		start = (t_map.conf.r[1] / 2) - (wall_hight / 2) \
		+ t_map.key.up_angle;
		ceiling(i, start, t_map.conf.c);
		walls(i, start, wall_hight, get_texture_num());
		flooor(i, (t_map.conf.r[1] / 2) + (wall_hight / 2) + \
		t_map.key.up_angle, t_map.conf.f);
		angle += FOV_ANGLE / t_map.conf.r[0];
	}
}

void		draw(void)
{
	t_map.img.img_ptr =
	mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr,
	&t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
	render_view();
	mlx_put_image_to_window(t_map.mlx_ptr, t_map.win_ptr,
	t_map.img.img_ptr, 0, 0);
}
