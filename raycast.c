/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 15:51:44 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		raycast(t_map *map)
{
	int i = 0;
	float x = map->player->axis.x;
	float y = map->player->axis.y;
	while (1)
	{
		x = cos(map->player->angle * M_PI / 180) * i + map->player->axis.x;
		y = sin(map->player->angle * M_PI / 180) * i + map->player->axis.y;
		if (map->grid[(int)y / SIZE][(int)x / SIZE] == '1')
			break ;
		i++;
	}
	return i;
}
