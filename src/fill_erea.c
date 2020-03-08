/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 23:13:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

int			shadow(int color)
{
	int r;
	int g;
	int b;

	r = color / pow(256, 2);
	g = (color / 256) % 256;
	b = color % 256;
	if ((g_map.ray.distance / 180) > 1)
	{
		r /= (g_map.ray.distance / 180);
		g /= (g_map.ray.distance / 180);
		b /= (g_map.ray.distance / 180);
	}
	color = pow(2, 16) * r + pow(2, 8) * g + b;
	return (color);
}

void		draw_walls(float x, float y, float height, int nbr)
{
	float	i;
	float	factor;
	int		color;

	i = 0;
	factor = (float)g_map.texture.height[nbr] / height;
	while (i < height)
	{
		color = g_map.texture.data[nbr][(int)(i * factor) * g_map.texture.width[nbr] + (int)g_map.ray.x_offset];
		y++;
		if (x < g_map.conf.r[0] && y < g_map.conf.r[1] && x > 0 && y > 0)
			g_map.img.data[(int)y * g_map.conf.r[0] + (int)x] = color;
		i++;
	}
}

void		draw_floor(float x, float y, int color)
{
	float	i;

	i = g_map.conf.r[1];
	while (i--)
	{
		y++;
		if (x < g_map.conf.r[0] && y < g_map.conf.r[1] && x > 0 && y > 0)
			g_map.img.data[(int)y * g_map.conf.r[0] + (int)x] = color;
	}
}

void		draw_ceiling(float x, float end, int color)
{
	int		i;

	i = 0;
	while (i < end)
	{
		i++;
		if (x < g_map.conf.r[0] && i < g_map.conf.r[1] && x > 0 && i > 0)
			g_map.img.data[(int)i * g_map.conf.r[0] + (int)x] = color;
	}
}
