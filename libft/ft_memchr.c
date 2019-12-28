/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:39:43 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/25 02:39:44 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *sr;
	size_t				i;

	sr = (const unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (sr[i] == (unsigned char)c)
			return ((unsigned char*)(s + i));
		i++;
	}
	return (0);
}
