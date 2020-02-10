/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/10 16:57:42 by mait-si-         ###   ########.fr       */
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

void	flooor(float x, float y, float width)
{
	int		i;
	int		j;

	i = 0;
	while (i < t_map.conf.r[1])
	{
		j = 0;
		x -= width;
		while (j < width)
		{
			render_px(x++, y, 0xe17055);
			j++;
		}
		y++;
		i++;
	}
}

void	ceiling(float y, float height)
{
	int		i;
	int		x;

	i = -1;
	x = 0;
	while (i++ < height)
	{
		x--;
		render_px(x++, y++, CEILLING);
	}
}
