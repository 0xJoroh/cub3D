/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:24:46 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/22 18:08:18 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start || !s[0])
	{
		if (!(str = (char *)malloc(1)))
			return (0);
		*str = '\0';
		return (str);
	}
	s += start;
	if (!(str = (char *)malloc(len * sizeof(char) + 1)))
		return (0);
	while (*s && len--)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
