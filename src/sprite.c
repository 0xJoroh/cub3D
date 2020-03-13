/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:17 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/13 23:52:47 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

t_sprite		*new_sprite(float x, float y, float distance, char c)
{
	t_sprite			*list;

	if (!(list = (t_sprite*)malloc(sizeof(*list) + 1)))
		return (0);
	if (c == '2')
		list->id = 0;
	else if (c == '4')
		list->id = 1;
	else if (c == '5')
		list->id = 2;
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

void			sort_sprite(void)
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
