/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:17 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/10 14:59:55 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

t_sprite		*new_sprite(float x, float y, float distance)
{
	t_sprite			*list;

	if (!(list = (t_sprite*)malloc(sizeof(*list) + 1)))
		return (0);
	list->x = x;
	list->y = y;
	list->distance = distance;
	list->next = NULL;
	return (list);
}

static t_sprite	*last_sprite(t_sprite *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void			add_sprite(t_sprite **alst, t_sprite *new)
{
	new->next = NULL;
	if (!*alst)
		*alst = new;
	else
		last_sprite(*alst)->next = new;
}

void	sort_sprite()
{
	t_sprite	*sprite;
	t_sprite	*before;
	t_sprite	*next;

	if (*g_sprites)
	{
		sprite = *g_sprites;
		before = 0;
		while (sprite->next)
		{
			next = sprite->next;
			if (sprite->distance < next->distance)
			{
				sprite->next = next->next;
				next->next = sprite;
				if (before)
					before->next = next;
				else
					*g_sprites = next;
				sprite = *g_sprites;
			}
			before = sprite;
			sprite = sprite->next;
		}
	}
}

void	render_sprite(int spt_size, int x_offset, int y_offset, float sprite_dist)
{
	int color;
	int i;
	int j;

	float angle = normalize_angle(g_map.ray.angle);
	i = -1;
	while (++i < spt_size)
	{

		ray_init(angle);
		if (x_offset + i < 0 || x_offset + i > g_map.conf.r[0])
			continue ;
		if (sprite_dist > g_zbuffer[i + x_offset] && (sprite_dist - g_zbuffer[i + x_offset]) > 40)
			continue ;
		j = -1;
		while (++j < spt_size)
		{
			if (y_offset + j < 0 || y_offset + j >= g_map.conf.r[1])
				continue ;
			color = g_map.texture.data[4][((j * g_map.texture.height[4] / spt_size) * g_map.texture.width[4]) + (i * g_map.texture.width[4] / spt_size)];
			if (color != 0)
				g_map.img.data[((int)(y_offset + j) * g_map.conf.r[0]) + (int)(x_offset + i)] = color;
		}
	}
}

void	sprite_position(t_sprite *sprite)
{
	int		spt_size;
	int		x_offset;
	int		y_offset;
	float	sprite_dir;

	float angle = normalize_angle(g_map.ray.angle);
	sprite->distance = distance(sprite->x, sprite->y, g_map.player.x, g_map.player.y);
	sprite_dir = atan2((sprite->y - g_map.player.y), (sprite->x - g_map.player.x));
	while (sprite_dir - angle > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - angle < -M_PI)
		sprite_dir += 2 * M_PI;
	if (g_map.conf.r[1] > g_map.conf.r[0])
		spt_size = (g_map.conf.r[1] / sprite->distance) * 64;
	else
		spt_size = (g_map.conf.r[0] / sprite->distance) * 64;
	x_offset = (sprite_dir - angle) * g_map.conf.r[0] / (FOV_ANGLE) + (g_map.conf.r[0] / 2 - spt_size / 2);
	y_offset = g_map.conf.r[1] / 2 - spt_size / 2;
	render_sprite(spt_size, x_offset, y_offset + g_map.key.up_angle, sprite->distance);
}

void		sprite_init()
{
	t_sprite *sprite;

	sprite = *g_sprites;
	while (sprite)
	{
		sprite->distance = distance(sprite->x, sprite->y, g_map.player.x, g_map.player.y);
		sprite = sprite->next;
	}
	sort_sprite();
}

void		generete_sprite()
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
