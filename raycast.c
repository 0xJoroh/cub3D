/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:33:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 23:57:21 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

float		raycast()
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
	// printf("(%f, %f)\n", x, y);
	// exit(1);
	return (float)sqrt(pow(x - playerX, 2) + pow(y - playerY, 2));
}
