/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:34:39 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 20:55:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		key_event()
{
	float x;
	float y;

	if (t_map.player.angle == 360 || t_map.player.angle == -360)
		t_map.player.angle = 0;
	x = cos(t_map.player.angle * M_PI / 180) * PLAYER_SPEED + t_map.player.x;
	y = sin(t_map.player.angle * M_PI / 180) * PLAYER_SPEED + t_map.player.y;
	if (t_map.key.forward && t_map.grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		t_map.player.x = x;
		t_map.player.y = y;
	}
	x = -cos(t_map.player.angle * M_PI / 180) * PLAYER_SPEED + t_map.player.x;
	y = -sin(t_map.player.angle * M_PI / 180) * PLAYER_SPEED + t_map.player.y;
	if (t_map.key.backward && t_map.grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		t_map.player.x = x;
		t_map.player.y = y;
	}
	x = cos((t_map.player.angle - 90) * M_PI / 180) * PLAYER_SPEED + t_map.player.x;
	y = sin((t_map.player.angle - 90) * M_PI / 180) * PLAYER_SPEED + t_map.player.y;
	if (t_map.key.left && t_map.grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		t_map.player.x = x;
		t_map.player.y = y;
	}
	x = cos((t_map.player.angle + 90) * M_PI / 180) * PLAYER_SPEED + t_map.player.x;
	y = sin((t_map.player.angle + 90) * M_PI / 180) * PLAYER_SPEED + t_map.player.y;
	if (t_map.key.right && t_map.grid[(int)y / SIZE][(int)x / SIZE] != '1')
	{
		t_map.player.x = x;
		t_map.player.y = y;
	}
	if (t_map.key.left_view)
		t_map.player.angle -= ROTATION_SPEED;
	if (t_map.key.right_view)
		t_map.player.angle += ROTATION_SPEED;
	if (t_map.key.quit)
		quit();
	if (t_map.key.left_view || t_map.key.right_view || t_map.key.right || t_map.key.left || t_map.key.forward || t_map.key.backward)
	{
		mlx_destroy_image(t_map.mlx_ptr, t_map.img.img_ptr);
		draw();
		printf("%f\n", t_map.player.angle);
	}
	return (0);
}

int key_releas(int keycode)
{
	if (keycode == 13)
		t_map.key.forward = 0;
	if (keycode == 1)
		t_map.key.backward = 0;
	if (keycode == 0)
		t_map.key.left = 0;
	if (keycode == 2)
		t_map.key.right = 0;
	if (keycode == 123)
		t_map.key.left_view = 0;
	if (keycode == 124)
		t_map.key.right_view = 0;
	if (keycode == 53)
		t_map.key.quit = 0;
	return 0;
}

int		key_press(int keycode)
{
	if (keycode == 13)
		t_map.key.forward = 1;
	if (keycode == 1)
		t_map.key.backward = 1;
	if (keycode == 0)
		t_map.key.left = 1;
	if (keycode == 2)
		t_map.key.right = 1;
	if (keycode == 123)
		t_map.key.left_view = 1;
	if (keycode == 124)
		t_map.key.right_view = 1;
	if (keycode == 53)
		t_map.key.quit = 1;
	return 0;
}
