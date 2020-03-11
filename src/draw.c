/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:55:09 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/11 21:36:17 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void		ray_init(float angle)
{
	angle = radtodeg(angle);
	if (angle > 360)
		angle = 0;
	g_map.ray.is_down = angle >= 0 && angle <= 180;
	g_map.ray.is_right = angle <= 90 || angle >= 270;
	g_map.ray.is_up = !g_map.ray.is_down;
	g_map.ray.is_left = !g_map.ray.is_right;
}

static int	get_texture_num(void)
{
	if (g_map.ray.wall_hit && g_map.ray.is_left)
		return (1);
	if (g_map.ray.wall_hit && g_map.ray.is_right)
		return (0);
	if (!g_map.ray.wall_hit && g_map.ray.is_up)
		return (3);
	if (!g_map.ray.wall_hit && g_map.ray.is_down)
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
	angle = normalize_angle(g_map.ray.angle - FOV_ANGLE / 2);
	while (++i < g_map.conf.r[0])
	{
		ray_init(angle);
		g_map.ray.distance = raycast(angle) * cosf(angle - g_map.ray.angle);
		g_zbuffer[i] = g_map.ray.distance;
		wall_hight = (SIZE / g_map.ray.distance) *
		((g_map.conf.r[0] / 2) / (tanf(FOV_ANGLE / 2)));
		start = (g_map.conf.r[1] / 2) - (wall_hight / 2) + g_map.key.up_angle;
		draw_ceiling(i, start, g_map.conf.c);
		draw_walls(i, start, wall_hight, get_texture_num());
		draw_floor(i, (g_map.conf.r[1] / 2) + (wall_hight / 2) +
		g_map.key.up_angle, g_map.conf.f);
		angle += FOV_ANGLE / g_map.conf.r[0];
	}
}

void		render_hud(void)
{
	int x;
	int height;
	int width;
	int y;

	height = 3;
	x = g_map.conf.r[0] / 2 - 25;
	y = g_map.conf.r[1] / 2 - 25;
	while (height--)
	{
		width = 25;
		while (width--)
			g_map.img.data[(int)y * g_map.conf.r[0] + (int)x++] = 0xffffff;
		x = g_map.conf.r[0] / 2 - 25;
		y++;
	}

	// x = g_map.conf.r[0] / 2 - 25;
	// y = g_map.conf.r[1] / 2 - 25;
	// width = 25;
	// while (width--)
	// {
	// 	height = 5;
	// 	while (height--)
	// 		g_map.img.data[(int)y++ * g_map.conf.r[0] + (int)x] = 0xffffff;
	// 	y = g_map.conf.r[1] / 2 - 25;
	// 	x++;
	// }
}

void		draw(void)
{
	g_map.img.img_ptr =
	mlx_new_image(g_map.mlx_ptr, g_map.conf.r[0], g_map.conf.r[1]);
	g_map.img.data = (int *)mlx_get_data_addr(g_map.img.img_ptr, &g_map.img.bpp,
	&g_map.img.size_l, &g_map.img.endian);
	render_view();
	generete_sprite();
	// render_hud();
	// render_lifebar();
	mlx_put_image_to_window(g_map.mlx_ptr, g_map.win_ptr,
	g_map.img.img_ptr, 0, 0);
}
