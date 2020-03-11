/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:34:39 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/11 21:35:19 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static void	check_angle(void)
{
	if (g_map.key.left_view)
		g_map.ray.angle -= degtorad(ROTATION_ANGLE);
	else if (g_map.key.right_view)
		g_map.ray.angle += degtorad(ROTATION_ANGLE);
	if (g_map.key.up_angle > 200)
		g_map.key.up_angle = 200;
	else if (g_map.key.up_angle < -250)
		g_map.key.up_angle = -250;
}

static void	check_position(void)
{
	float	x;
	float	y;

	x = cosf(g_map.ray.angle) * PLAYER_SPEED + g_map.player.x;
	y = sinf(g_map.ray.angle) * PLAYER_SPEED + g_map.player.y;
	if (g_map.key.forward && !collision(x, y, '1') && !collision(x, y, '2'))
	{
		g_map.player.x = x;
		g_map.player.y = y;
	}
	x = -cosf(g_map.ray.angle) * PLAYER_SPEED + g_map.player.x;
	y = -sinf(g_map.ray.angle) * PLAYER_SPEED + g_map.player.y;
	if (g_map.key.backward && !collision(x, y, '1') && !collision(x, y, '2'))
	{
		g_map.player.x = x;
		g_map.player.y = y;
	}
	x = cosf(g_map.ray.angle - (M_PI / 2)) * PLAYER_SPEED + g_map.player.x;
	y = sinf(g_map.ray.angle - (M_PI / 2)) * PLAYER_SPEED + g_map.player.y;
	if (g_map.key.left && !collision(x, y, '1') && !collision(x, y, '2'))
	{
		g_map.player.x = x;
		g_map.player.y = y;
	}
}

int			loop_hook(void)
{
	float x;
	float y;

	if (g_map.key.quit)
		quit();
	if (g_map.key.left_view || g_map.key.right_view || g_map.key.right ||
	g_map.key.left || g_map.key.forward ||
	g_map.key.backward || g_map.key.up_view)
	{
		check_angle();
		check_position();
		x = cosf(g_map.ray.angle + (M_PI / 2)) * PLAYER_SPEED + g_map.player.x;
		y = sinf(g_map.ray.angle + (M_PI / 2)) * PLAYER_SPEED + g_map.player.y;
		if (g_map.key.right && !collision(x, y, '1') && !collision(x, y, '2'))
		{
			g_map.player.x = x;
			g_map.player.y = y;
		}
		mlx_destroy_image(g_map.mlx_ptr, g_map.img.img_ptr);
		draw();
	}
	return (0);
}

int			key_releas(int keycode)
{
	if (keycode == 13)
		g_map.key.forward = 0;
	if (keycode == 1)
		g_map.key.backward = 0;
	if (keycode == 0)
		g_map.key.left = 0;
	if (keycode == 2)
		g_map.key.right = 0;
	if (keycode == 123)
		g_map.key.left_view = 0;
	if (keycode == 124)
		g_map.key.right_view = 0;
	if (keycode == 126 || keycode == 125)
		g_map.key.up_view = 0;
	if (keycode == 53)
		g_map.key.quit = 0;
	return (0);
}

int			key_press(int keycode)
{
	if (keycode == 13)
		g_map.key.forward = 1;
	if (keycode == 1)
		g_map.key.backward = 1;
	if (keycode == 0)
		g_map.key.left = 1;
	if (keycode == 2)
		g_map.key.right = 1;
	if (keycode == 123)
		g_map.key.left_view = 1;
	if (keycode == 124)
		g_map.key.right_view = 1;
	if (keycode == 126 || keycode == 125)
		g_map.key.up_view = 1;
	if (keycode == 126)
		g_map.key.up_angle += 15;
	if (keycode == 125)
		g_map.key.up_angle -= 15;
	if (keycode == 53)
		g_map.key.quit = 1;
	return (0);
}
