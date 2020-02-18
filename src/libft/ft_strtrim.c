/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:36:42 by mait-si-          #+#    #+#             */
/*   Updated: 2019/10/22 10:55:44 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end(char *s1, char *set)
{
	int i;
	int j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			if (i <= 0)
				return (0);
			i--;
		}
		else
			j++;
	}
	return (i);
}

static int	start(char *s1, char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	start_;
	int	end_;
	int	len;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	if (s1[0] == '\0')
		return ("\0");
	len = 0;
	start_ = start((char *)s1, (char *)set);
	end_ = end((char *)s1, (char *)set);
	while (start_++ <= end_)
		len++;
	start_ -= len + 1;
	return (ft_substr(s1, start_, len));
}
