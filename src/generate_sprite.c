/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:21:08 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/11 21:34:34 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static void	draw_sprite(int spt_size, int x, int y, int i)
{
	int	color;
	int j;

	j = -1;
	while (++j < spt_size)
	{
		if (y + j < 0 || y + j >= g_map.conf.r[1])
			continue ;
		color = g_map.texture.data[4]
		[((j * g_map.texture.height[4] / spt_size) *
		g_map.texture.width[4]) + (i * g_map.texture.width[4] / spt_size)];
		if (color != 0)
			g_map.img.data[((int)(y + j) *
			g_map.conf.r[0]) + (int)(x + i)] = shadow(color);
	}
}

static void	render_sprite(int spt_size, int x, int y, float sprt_dst)
{
	int		i;
	float	angle;

	angle = normalize_angle(g_map.ray.angle);
	i = -1;
	while (++i < spt_size)
	{
		ray_init(angle);
		if (x + i < 0 || x + i > g_map.conf.r[0])
			continue ;
		if (sprt_dst > g_zbuffer[i + x] && (sprt_dst - g_zbuffer[i + x]) > 40)
			continue ;
		draw_sprite(spt_size, x, y, i);
	}
}

static void	sprite_position(t_sprite *sprite)
{
	int		spt_size;
	int		x;
	int		y;
	float	sprite_dir;
	float	angle;

	angle = normalize_angle(g_map.ray.angle);
	sprite->distance =
	distance(sprite->x, sprite->y, g_map.player.x, g_map.player.y);
	sprite_dir =
	atan2((sprite->y - g_map.player.y), (sprite->x - g_map.player.x));
	while (sprite_dir - angle > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - angle < -M_PI)
		sprite_dir += 2 * M_PI;
	if (g_map.conf.r[1] > g_map.conf.r[0])
		spt_size = (g_map.conf.r[1] / sprite->distance) * 64;
	else
		spt_size = (g_map.conf.r[0] / sprite->distance) * 64;
	x = (sprite_dir - angle) *
	g_map.conf.r[0] / (FOV_ANGLE) + (g_map.conf.r[0] / 2 - spt_size / 2);
	y = g_map.conf.r[1] / 2 - spt_size / 2;
	render_sprite(spt_size, x, y + g_map.key.up_angle, sprite->distance);
}

static void	sprite_init(void)
{
	t_sprite *sprite;

	sprite = *g_sprites;
	while (sprite)
	{
		sprite->distance =
		distance(sprite->x, sprite->y, g_map.player.x, g_map.player.y);
		sprite = sprite->next;
	}
	sort_sprite();
}

void		generete_sprite(void)
{
	t_sprite *sprite;

	sprite_init();
	sprite = *g_sprites;
	while (sprite)
	{
		sprite_position(sprite);
		sprite = sprite->next;
	}
}
