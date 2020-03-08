/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:50:47 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 10:49:16 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

// void	render_px(float x, float y, int color)
// {
// 	if (x < t_map.conf.r[0] && y < t_map.conf.r[1] && x > 0 && y > 0)
// 		t_map.img.data[(int)y * t_map.conf.r[0] + (int)x] = color;
// }

float	degtorad(float deg)
{
	return (deg * (M_PI / 180));
}

float	radtodeg(float rad)
{
	return (rad * (180 / M_PI));
}

float	normalize_angle(float angle)
{
	angle = (float)fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	freeing(char **words)
{
	int i;

	i = 0;
	if (words)
	{
		while (words[i])
			free(words[i++]);
		free(words);
	}
}
