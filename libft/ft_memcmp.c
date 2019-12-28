/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:39:38 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/25 02:39:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *sr1;
	unsigned const char *sr2;

	sr1 = (unsigned const char *)s1;
	sr2 = (unsigned const char *)s2;
	while (n--)
	{
		if (*sr1 != *sr2)
			return (*sr1 - *sr2);
		sr1++;
		sr2++;
	}
	return (0);
}
