/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 10:18:20 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static float	horizontal(float player_x, float player_y, float angle)
{
	float	ay;
	float	xstep;
	float	ystep;

	ay = floor(player_y / SIZE) * SIZE;
	ay += t_map.ray.is_down ? SIZE : 0;
	t_map.ray.x = player_x + (ay - player_y) / tanf(angle);
	ystep = SIZE;
	ystep *= t_map.ray.is_up ? -1 : 1;
	xstep = SIZE / tanf(angle);
	xstep *= t_map.ray.is_left && xstep > 0 ? -1 : 1;
	xstep *= t_map.ray.is_right && xstep < 0 ? -1 : 1;
	if (t_map.ray.is_up)
		ay--;
	while (!collision(t_map.ray.x, ay, '1'))
	{
		t_map.ray.x += xstep;
		ay += ystep;
	}
	if (t_map.ray.is_up)
		ay++;
	return (distance(t_map.ray.x, player_x, ay, player_y));
}

static float	verticale(float player_x, float player_y, float angle)
{
	float	ax;
	float	xstep;
	float	ystep;

	ax = floor(player_x / SIZE) * SIZE;
	ax += t_map.ray.is_right ? SIZE : 0;
	t_map.ray.y = player_y + (ax - player_x) * tanf(angle);
	xstep = SIZE;
	xstep *= t_map.ray.is_left ? -1 : 1;
	ystep = SIZE * tanf(angle);
	ystep *= t_map.ray.is_up && ystep > 0 ? -1 : 1;
	ystep *= t_map.ray.is_down && ystep < 0 ? -1 : 1;
	if (t_map.ray.is_left)
		ax--;
	while (!collision(ax, t_map.ray.y, '1'))
	{
		ax += xstep;
		t_map.ray.y += ystep;
	}
	if (t_map.ray.is_left)
		ax++;
	return (distance(ax, player_x, t_map.ray.y, player_y));
}

float			raycast(float angle)
{
	float		h;
	float		v;

	h = horizontal(t_map.player.x, t_map.player.y, angle);
	v = verticale(t_map.player.x, t_map.player.y, angle);
	t_map.ray.wall_hit = (v < h) ? 1 : 0;
	t_map.ray.x_offset = t_map.ray.wall_hit ?
	fmod(t_map.ray.y, SIZE) : fmod(t_map.ray.x, SIZE);
	return ((h < v) ? h : v);
}
