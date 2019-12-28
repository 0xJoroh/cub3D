/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:38:56 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/25 02:38:57 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lend;
	size_t lens;
	size_t len;
	size_t i;

	if (size == 0)
		return (ft_strlen(src));
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	len = lens + lend;
	i = 0;
	if (size < lend)
		len = (lens + size);
	if (size > lend)
	{
		while (src[i] && (lend + i) < (size - 1))
		{
			dst[lend + i] = src[i];
			i++;
		}
		dst[lend + i] = '\0';
		len = (lens + lend);
	}
	return (len);
}
