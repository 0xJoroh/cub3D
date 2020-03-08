/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 23:13:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static float	horizontal(float player_x, float player_y, float angle)
{
	float	ay;
	float	xstep;
	float	ystep;

	ay = floor(player_y / SIZE) * SIZE;
	ay += g_map.ray.is_down ? SIZE : 0;
	g_map.ray.x = player_x + (ay - player_y) / tanf(angle);
	ystep = SIZE;
	ystep *= g_map.ray.is_up ? -1 : 1;
	xstep = SIZE / tanf(angle);
	xstep *= g_map.ray.is_left && xstep > 0 ? -1 : 1;
	xstep *= g_map.ray.is_right && xstep < 0 ? -1 : 1;
	if (g_map.ray.is_up)
		ay--;
	while (!collision(g_map.ray.x, ay, '1'))
	{
		g_map.ray.x += xstep;
		ay += ystep;
	}
	if (g_map.ray.is_up)
		ay++;
	return (distance(g_map.ray.x, player_y, player_x, ay));
}

static float	verticale(float player_x, float player_y, float angle)
{
	float	ax;
	float	xstep;
	float	ystep;

	ax = floor(player_x / SIZE) * SIZE;
	ax += g_map.ray.is_right ? SIZE : 0;
	g_map.ray.y = player_y + (ax - player_x) * tanf(angle);
	xstep = SIZE;
	xstep *= g_map.ray.is_left ? -1 : 1;
	ystep = SIZE * tanf(angle);
	ystep *= g_map.ray.is_up && ystep > 0 ? -1 : 1;
	ystep *= g_map.ray.is_down && ystep < 0 ? -1 : 1;
	if (g_map.ray.is_left)
		ax--;
	while (!collision(ax, g_map.ray.y, '1'))
	{
		ax += xstep;
		g_map.ray.y += ystep;
	}
	if (g_map.ray.is_left)
		ax++;
	return (distance(ax, g_map.ray.y, player_x, player_y));
}

float			raycast(float angle)
{
	float		h;
	float		v;

	h = horizontal(g_map.player.x, g_map.player.y, angle);
	v = verticale(g_map.player.x, g_map.player.y, angle);
	g_map.ray.wall_hit = (v < h) ? 1 : 0;
	g_map.ray.x_offset = g_map.ray.wall_hit ?
	fmod(g_map.ray.y, SIZE) : fmod(g_map.ray.x, SIZE);
	return ((h < v) ? h : v);
}
