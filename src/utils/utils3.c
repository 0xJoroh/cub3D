/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:24:35 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/12 14:07:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return ((float)sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2)));
}

int		surounded_walls(int x, int y)
{
	if (g_map.conf.grid[x][y - 1] == ' ' || g_map.conf.grid[x][y + 1] == ' ' ||
	g_map.conf.grid[x - 1][y] == ' ' || g_map.conf.grid[x + 1][y] == ' ')
		ft_puterror("map must be surounded by walls.");
	return (0);
}

void	render_lifebar_cadr(float x, float y, int width, int height)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			g_map.img.data[(int)(i + y) * g_map.conf.r[0] + (int)(j + x)] =
			0x123456;
	}
}

void	render_lifebar(float x, float y, int width, int height)
{
	int i;
	int j;

	i = -1;
	render_lifebar_cadr(19, 19, 202, 32);
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			g_map.img.data[(int)(i + y) * g_map.conf.r[0] + (int)(j + x)] =
			0xe74c3c;
	}
}

void	check_collision(void)
{
	if (collision(g_map.player.x, g_map.player.y, '5'))
	{
		g_map.life_bar -= 30;
		g_map.conf.grid[(int)(g_map.player.y / SIZE)]
		[(int)(g_map.player.x / SIZE)] = '0';
	}
	if (collision(g_map.player.x, g_map.player.y, '4'))
	{
		if (g_map.life_bar <= 170)
			g_map.life_bar += 30;
	}
	// if (collision(g_map.player.x, g_map.player.y, '6'))
	// {

	// }
}
