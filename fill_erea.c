/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/12 21:56:09 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "textures/1.xpm"

void	walls(float x, float y, float height, int color)
{
	int		i;

	i = -1;
	while (i++ < height)
	{
		x--;
		render_px(x++, y++, color);
	}
}

void	flooor(float x, float y, int color)
{
	int		i;

	i = 0;
	while (i < t_map.conf.r[1])
	{
		x--;
		render_px(x++, y++, color);
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

int		get_texture(void)
{
	if (t_map.ray.wall_hit)
	{
		if (t_map.ray.is_right)
			return (0x11cccc);
		if (t_map.ray.is_left)
			return (0xffdddf);
	}
	if (!t_map.ray.wall_hit)
	{
		if (t_map.ray.is_up)
			return (0xfeeeee);
		if (t_map.ray.is_down)
			return (0xeeffff);
	}
	return (0x321654);
}
