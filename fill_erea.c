/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/11 14:29:49 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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
		x --;
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
			return (0xcccccc);
		if (t_map.ray.is_left)
			return (0x996633);
	}
	if (!t_map.ray.wall_hit)
	{
		if (t_map.ray.is_up)
			return (0x123456);
		if (t_map.ray.is_down)
			return (0x321654);
	}
	return (0x321654);
}
