/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:50:35 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/26 12:13:04 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_sprite **alst, t_sprite *new)
{
	new->next = NULL;
	if (!*alst)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}
