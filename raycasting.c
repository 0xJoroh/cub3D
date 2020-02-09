/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/09 03:02:06 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ray_init()
{
	if (t_map.key.left_view)
		t_map.ray.angle -= degtorad(ROTATION_SPEED);
	if (t_map.key.right_view)
		t_map.ray.angle += degtorad(ROTATION_SPEED);
	t_map.ray.angle = normalize_angle(t_map.ray.angle);
	t_map.ray.is_down = (t_map.ray.angle < M_PI && t_map.ray.angle > 0) || (t_map.ray.angle < -M_PI && t_map.ray.angle < 0);
	t_map.ray.is_up = !t_map.ray.is_down;
	t_map.ray.is_right = t_map.ray.angle > M_PI * 1.5 && t_map.ray.angle > M_PI / 2;
	t_map.ray.is_left = !t_map.ray.is_right;
	t_map.ray.distance = 0;
}

int		horizontal(float playerX, float playerY, float angle)
{
	float	ay;
	float	ax;
	float	xstep;
	float	ystep;

	ay = (float)floor(playerY / SIZE) * SIZE;
	ay += t_map.ray.is_down ? SIZE : 0;
	ax = playerX + (ay - playerY) / tan(angle);
	ystep = SIZE;
	ystep *= t_map.ray.is_up ? -1 : 1;
	xstep = SIZE / tan(angle);
	xstep *= t_map.ray.is_left && xstep > 0 ? -1 : 1;
	xstep *= t_map.ray.is_right && xstep < 0 ? -1 : 1;
	if (t_map.ray.is_up)
		ay--;
	while (ax >= 0 && ax <= (float)t_map.conf.r[0] && ay >= 0 && ay <= (float)t_map.conf.r[2])
	{
		if (wall_collision(ax, ay))
			return ((int)sqrt(pow(ax - playerX, 2) + pow(ay - playerY, 2)));
		ax += xstep;
		ay += ystep;
	}
	return (0);
}

int		verticale(float playerX, float playerY, float angle)
{
	float	ay;
	float	ax;
	float	xstep;
	float	ystep;

	ax = (float)floor(playerX / SIZE) * SIZE;
	ax += t_map.ray.is_right ? SIZE : 0;

	ay = (float)playerY + (ax - playerX) * tan(angle);

	xstep = SIZE;
	xstep *= t_map.ray.is_left ? -1 : 1;

	ystep = SIZE * tan(angle);
	ystep *= t_map.ray.is_up && ystep > 0 ? -1 : 1;
	ystep *= t_map.ray.is_down && ystep < 0 ? -1 : 1;

	if (t_map.ray.is_left)
		ax--;
	while (ax >= 0 && ax <= (float)t_map.conf.r[0] && ay >= 0 && ay <= (float)t_map.conf.r[2])
	{
		if (wall_collision(ax, ay))
			return ((int)sqrt(pow(ax - playerX, 2) + pow(ay - playerY, 2)));
		ax += xstep;
		ay += ystep;
	}
	return ((int)sqrt(pow(ax - playerX, 2) + pow(ay - playerY, 2)));
}

int		raycast()
{
	int		h;
	int		v;

	h = horizontal(t_map.player.x, t_map.player.y, t_map.ray.angle);
	v = verticale(t_map.player.x, t_map.player.y, t_map.ray.angle);
	printf("%d, %d\n", h, v);
	return ((h < v) ? h : v);
}
