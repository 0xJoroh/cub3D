/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 20:55:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		raycast()
{
	int i = 0;
	float x = t_map.player.x;
	float y = t_map.player.y;
	while (1)
	{
		x = cos(t_map.player.angle * M_PI / 180) * i + t_map.player.x;
		y = sin(t_map.player.angle * M_PI / 180) * i + t_map.player.y;
		if (t_map.grid[(int)y / SIZE][(int)x / SIZE] == '1')
			break ;
		i++;
	}
	return i;
}
