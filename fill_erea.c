/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/10 00:54:21 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	walls(float x, float y, float width, float height)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		x -= width;
		while (j < width)
		{
			render_px(x++, y, PLAYER);
			j++;
		}
		y++;
		i++;
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

void	ceiling(float x, float y, float width, float height)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		x -= width;
		while (j < width)
		{
			render_px(x++, y, 0x74b9ff);
			j++;
		}
		y++;
		i++;
	}
}
