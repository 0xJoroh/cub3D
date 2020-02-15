/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/15 15:55:09 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		walls(float x, float y, float height)
{
	float	i;
	float	factor;

	i = 0;
	factor = (float)t_map.texture.height / height;
	while (i < height)
	{
		int color = t_map.texture.data[(int)(i * factor) % 64 * t_map.texture.width + (int)t_map.ray.x_offset % 64];
		render_px(x, i + y, color);
		i++;
	}
}

void	flooor(float x, float y, int color)
{
	float	i;
	float	factor;
	float	height = t_map.conf.r[1] - y;

	i = 0;
	color = 0;
	factor = (float)t_map.texture.height / height;
	while (i < height)
	{
		int color = t_map.texture.data[(int)(i * factor) % 64 * t_map.texture.width + (int)t_map.ray.x_offset % 64];
		render_px(x, i + y, color);
		i++;
	}
}

void	ceiling(float x, float end, int color)
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
