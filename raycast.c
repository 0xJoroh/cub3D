/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/08 00:26:13 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		raycast()
{
	float playerX = t_map.player.x;
	float playerY = t_map.player.y;
	float y = (float)floor(playerY / SIZE) * SIZE;
	float x = (float)playerX + ((playerY - y) / tan(degtorad(t_map.player.angle)));
	// while (wall_collision(x, y))
	// {
	// 	y += (float)SIZE;
	// 	x += (float)SIZE / tan(degtorad(t_map.player.angle));
	// }
	int	dist = (int)sqrt(pow(x - playerX, 2) + pow(y - playerY, 2));
	dist = (dist > WIN_WIDTH) ? WIN_WIDTH : dist;
	printf("%d\n", dist);
	return dist;
}
