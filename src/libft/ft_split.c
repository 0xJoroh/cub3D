/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:19:50 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/21 16:37:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_num(char const *str, char c)
{
	int var;
	int counter;

	var = 0;
	counter = 0;
	while (*str)
	{
		if (*str == c)
			var = 0;
		else if (var == 0)
		{
			var = 1;
			counter++;
		}
		str++;
	}
	return (counter);
}

static int		ft_strlenword(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void		*freeing(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		counter;
	char	**tab;
	int		i;

	if (!s || !ft_strcmp(s, ""))
		return (NULL);
	counter = words_num((char *)s, c);
	if (!(tab = (char **)malloc((counter + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (counter--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_substr((char *)s, 0, ft_strlenword((char *)s, c));
		if (!tab[i])
			return (freeing(tab, i));
		s = s + ft_strlenword((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
