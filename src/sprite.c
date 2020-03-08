/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:17 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 16:13:16 by mait-si-         ###   ########.fr       */
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

void			sort_sprite(t_sprite **head)
{
	t_sprite	*tmp1;
	t_sprite	*tmp2;
	float		dist;

	tmp1 = *head;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->distance < tmp1->distance)
			{
				dist = tmp1->distance;
				tmp1->distance = tmp2->distance;
				tmp2->distance = dist;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}








// void	ft_draw_sprit()
// {
// 	int j;
// 	int *add;
// 	int a;

// 	ptr->y = 0;
// 	j = 0;
// 	add = (int*)mlx_get_data_addr(ptr->img_xpm_sprit, &a, &a, &a);
// 	while (ptr->y++ < ptr->spt_size - 1)
// 	{
// 		if (ptr->x_sp + ptr->y < 0 || ptr->x_sp + ptr->y > ptr->size_map_x)
// 			continue;
// 		if (g_head->ds_sprit >= g_sprit[ptr->x_sp + ((int)ptr->y)] && (g_head->ds_sprit - g_sprit[ptr->x_sp + ((int)ptr->y)]) > 40)
// 			continue;
// 		j = 0;
// 		while (j++ < ptr->spt_size - 1)
// 		{
// 			if (ptr->y_sp + j < 0 || ptr->y_sp + j > ptr->size_map_y)
// 				continue;
// 			ptr->color = add[(ptr->s_x * (j * ptr->s_y / ptr->spt_size)) + (((int)ptr->y) * ptr->s_x / ptr->spt_size)];
// 			if (ptr->color != add[0])
// 				img_put((ptr->x_sp + ((int)ptr->y)), ptr->y_sp + j, ptr);
// 		}
// 	}
// }






static void	render_sprite(int spt_size, int x_ofst, int y_ofst)
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < spt_size)
	{
		if (x_ofst + i < 0 || x_ofst + i > t_map.conf.r[0])
			continue ;
		// if (game->ray[x_ofst + i].dist <= sprite->distance)
		// 	continue ;
		j = -1;
		while (++j < spt_size)
		{
			if (y_ofst + j < 0 || y_ofst + j >= t_map.conf.r[1])
				continue ;
			color = t_map.texture.data[4][i * t_map.texture.width[4] / spt_size) + (j * t_map.texture.width[4] / spt_size];
			if (color != 0)
				t_map.texture.data[4][(y_ofst + j) * t_map.conf.r[0] + (t_map.conf.r[0] + x_ofst + i)] = color;
		}
	}
}

static void	sprite_position(t_sprite *sprite)
{
	int		spt_size;
	int		x_ofst;
	int		y_ofst;
	float	sprite_dir;

	sprite_dir = atan2(sprite->y - t_map.player.y, sprite->x - t_map.player.x);
	while (sprite_dir - t_map.ray.angle > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - t_map.ray.angle < -M_PI)
		sprite_dir += 2 * M_PI;
	if (t_map.conf.r[1] > t_map.conf.r[0])
		spt_size = t_map.conf.r[1] / sprite->distance;
	else
		spt_size = t_map.conf.r[0] / sprite->distance;
	x_ofst = (sprite_dir - t_map.ray.angle) *
		t_map.conf.r[0] / FOV_ANGLE + (t_map.conf.r[0] / 2 - spt_size / 2);
	y_ofst = (t_map.conf.r[0] / 2) - spt_size / 2;
	render_sprite(spt_size, x_ofst, y_ofst);
}

void		generete_sprite()
{
	t_sprite *sprite;

	sprite = *g_sprites;
	while (sprite)
	{
		sprite_position(sprite);
		sprite = sprite->next;
	}
}




// void	ft_cal_ds(t_win *ptr)
// {
// 	float a;

// 	ptr->sp_dr = atan2(g_head->y_sprit - ptr->y_origine,
// 	g_head->x_sprit - ptr->x_origine);
// 	while (ptr->sp_dr - ptr->angle * (M_PI / 180) > M_PI)
// 		ptr->sp_dr -= 2 * M_PI;
// 	while (ptr->sp_dr - ptr->angle * (M_PI / 180) < -M_PI)
// 		ptr->sp_dr += 2 * M_PI;
// 	if (ptr->size_map_x > ptr->size_map_y)
// 		ptr->spt_size = (ptr->size_map_x / g_head->ds_sprit) * ptr->size_square;
// 	else
// 		ptr->spt_size = (ptr->size_map_y / g_head->ds_sprit) * ptr->size_square;
// 	ptr->y_sp = (ptr->size_map_y / 2) - (ptr->spt_size / 2);
// 	a = ptr->sp_dr - ptr->angle;
// 	ptr->x_sp = (ptr->sp_dr - ptr->angle * (M_PI / 180)) / g_fov_angle *
// 	ptr->size_map_x + (ptr->size_map_x / 2 - ptr->spt_size / 2);
// 	ft_draw_sprit();
// }
