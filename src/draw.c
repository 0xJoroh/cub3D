/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:55:09 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 16:13:31 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static void	ray_init(float angle)
{
	angle = radtodeg(angle);
	if (angle > 360)
		angle = 0;
	t_map.ray.is_down = angle >= 0 && angle <= 180;
	t_map.ray.is_right = angle <= 90 || angle >= 270;
	t_map.ray.is_up = !t_map.ray.is_down;
	t_map.ray.is_left = !t_map.ray.is_right;
	angle = degtorad(angle);
}

int	get_texture_num(void)
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

static void	render_view(void)
{
	int		i;
	float	wall_hight;
	float	angle;
	float	start;

	i = -1;
	angle = normalize_angle(t_map.ray.angle - FOV_ANGLE / 2);
	while (++i < t_map.conf.r[0])
	{
		ray_init(angle);
		t_map.ray.distance = raycast(angle) * cosf(angle - t_map.ray.angle);
		wall_hight = (SIZE / t_map.ray.distance) * ((t_map.conf.r[0] / 2) / (tanf(FOV_ANGLE / 2)));
		start = (t_map.conf.r[1] / 2) - (wall_hight / 2) + t_map.key.up_angle;
		printf("%f, %f\n", start, wall_hight);
		draw_ceiling(i, start, t_map.conf.c);
		draw_walls(i, start, wall_hight, get_texture_num());
		draw_floor(i, (t_map.conf.r[1] / 2) + (wall_hight / 2) + t_map.key.up_angle, t_map.conf.f);
		angle += FOV_ANGLE / t_map.conf.r[0];
	}
}

void		draw(void)
{
	t_map.img.img_ptr = mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr, &t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
	render_view();
	generete_sprite();
	mlx_put_image_to_window(t_map.mlx_ptr, t_map.win_ptr, t_map.img.img_ptr, 0, 0);
}
