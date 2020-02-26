/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:15:22 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/26 12:16:33 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sprite	*ft_lstnew(float x, float y, float distance)
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
