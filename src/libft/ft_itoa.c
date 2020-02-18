/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:00:47 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/22 10:54:42 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len(unsigned int nbr)
{
	unsigned int	size;

	size = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	i;
	unsigned int	size;

	nbr = ((n < 0) ? (unsigned int)(n * -1) : (unsigned int)n);
	size = len(nbr);
	i = 0;
	if (!(str = (char*)malloc(size + 1 + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nbr >= 10)
	{
		str[i--] = (char)(nbr % 10 + 48);
		nbr /= 10;
	}
	str[i] = (char)(nbr % 10 + 48);
	str[size] = '\0';
	return (str);
}
