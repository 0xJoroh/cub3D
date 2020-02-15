/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_erea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:49:29 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/13 17:16:43 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "textures/1.xpm"

// void	walls(float x, float y, float height)
// {
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	while (i < height)
// 	{
// 		x--;
// 		render_px(x++, y++, t_map.texture.texture[i++][j++]);
// 	}
// }

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
