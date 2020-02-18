/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/18 17:22:32 by mait-si-         ###   ########.fr       */
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
	if ((t_map.ray.distance / 180) > 1)
	{
		r /= (t_map.ray.distance / 180);
		g /= (t_map.ray.distance / 180);
		b /= (t_map.ray.distance / 180);
	}
	color = pow(2, 16) * r + pow(2, 8) * g + b;
	return (color);
}

void		walls(float x, float y, float height, int nbr)
{
	float	i;
	float	factor;
	int		color;

	i = 0;
	factor = (float)t_map.texture.height[nbr] / height;
	while (i < height)
	{
		color = t_map.texture.data[nbr][(int)(i * factor) * \
		t_map.texture.width[nbr] + (int)t_map.ray.x_offset];
		render_px(x, i + y, shadow(color));
		i++;
	}
}

void		flooor(float x, float y, int color)
{
	float	i;

	i = 0;
	while (i < t_map.conf.r[1])
	{
		x--;
		render_px(x++, y++, color);
		i++;
	}
}

void		ceiling(float x, float end, int color)
{
	int		i;
	int		y;

	i = -1;
	y = 0;
	while (i++ < end)
	{
		x--;
		render_px(x++, y++, color);
	}
}
