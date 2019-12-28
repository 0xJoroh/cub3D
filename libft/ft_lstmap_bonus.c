/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:51:52 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/22 19:42:21 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ptr;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	ptr = lst;
	new = ft_lstnew(f(ptr->content));
	ptr = ptr->next;
	while (ptr)
	{
		if (!(elem = ft_lstnew(f(ptr->content))))
		{
			ft_lstclear(&new, del);
			new = NULL;
			break ;
		}
		ft_lstadd_back(&new, elem);
		ptr = ptr->next;
	}
	return (new);
}
