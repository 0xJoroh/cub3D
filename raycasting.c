/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/17 14:03:55 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int				wall_collision(float x, float y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (t_map.grid[0][i])
		i++;
	while (t_map.grid[j])
		j++;
	if (x > 0 && y > 0)
		if ((int)y / SIZE < j && (int)x / SIZE < i)
			return (t_map.grid[(int)y / SIZE][(int)x / SIZE] == '1');
	return (1);
}

void			ray_init(float angle)
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

static float	horizontal(float player_x, float player_y, float angle)
{
	float	ay;
	float	xstep;
	float	ystep;

	ay = floor(player_y / SIZE) * SIZE;
	ay += t_map.ray.is_down ? SIZE : 0;
	t_map.ray.x = player_x + (ay - player_y) / tan(angle);
	ystep = SIZE;
	ystep *= t_map.ray.is_up ? -1 : 1;
	xstep = SIZE / tan(angle);
	xstep *= t_map.ray.is_left && xstep > 0 ? -1 : 1;
	xstep *= t_map.ray.is_right && xstep < 0 ? -1 : 1;
	if (t_map.ray.is_up)
		ay--;
	while (!wall_collision(t_map.ray.x, ay))
	{
		t_map.ray.x += xstep;
		ay += ystep;
	}
	if (t_map.ray.is_up)
		ay++;
	return (sqrt(pow(t_map.ray.x - player_x, 2) + pow(ay - player_y, 2)));
}

static float	verticale(float player_x, float player_y, float angle)
{
	float	ax;
	float	xstep;
	float	ystep;

	ax = floor(player_x / SIZE) * SIZE;
	ax += t_map.ray.is_right ? SIZE : 0;
	t_map.ray.y = player_y + (ax - player_x) * tan(angle);
	xstep = SIZE;
	xstep *= t_map.ray.is_left ? -1 : 1;
	ystep = SIZE * tan(angle);
	ystep *= t_map.ray.is_up && ystep > 0 ? -1 : 1;
	ystep *= t_map.ray.is_down && ystep < 0 ? -1 : 1;
	if (t_map.ray.is_left)
		ax--;
	while (!wall_collision(ax, t_map.ray.y))
	{
		ax += xstep;
		t_map.ray.y += ystep;
	}
	if (t_map.ray.is_left)
		ax++;
	return (sqrt(pow(ax - player_x, 2) + pow(t_map.ray.y - player_y, 2)));
}

float			raycast(float angle)
{
	float		h;
	float		v;

	h = horizontal(t_map.player.x, t_map.player.y, angle);
	v = verticale(t_map.player.x, t_map.player.y, angle);
	t_map.ray.wall_hit = (v < h) ? 1 : 0;
	t_map.ray.x_offset = t_map.ray.wall_hit ? fmod(t_map.ray.y, SIZE) : fmod(t_map.ray.x, SIZE);
	return ((h < v) ? h : v);
}
