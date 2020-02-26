/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:05:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/26 13:34:29 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_sprite *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		len++;
		// printf("s%d(%f, %f)\tDistance => %f\n", len, lst->x, lst->y, lst->distance);
		lst = lst->next;
	}
	return (len);
}
