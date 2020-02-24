/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:19:50 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/24 12:29:53 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeing(char **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

static int	counter(char const *str, char c)
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

static void	fill_words(char const *str, char **words, char c)
{
	int i;
	int j;

	i = 0;
	while (*str)
	{
		j = 0;
		while (*str != c && *str)
			words[i][j++] = *str++;
		if (j)
			words[i++][j] = '\0';
		if (*str == '\0')
			break ;
		str++;
	}
}

static void	memallo(int split_count, char **w, char const *str, char c)
{
	int letter_counter;
	int i;

	i = 0;
	while (split_count--)
	{
		letter_counter = 0;
		if (*str == c)
		{
			str++;
			split_count++;
		}
		while (*str && *str != c)
		{
			letter_counter++;
			str++;
		}
		if (letter_counter)
			if (!(w[i++] = (char *)malloc(sizeof(char) * (letter_counter + 1))))
				freeing(w);
	}
	if (i >= 0)
		w[i] = 0;
}

char		**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (0);
	if (!(words = (char **)malloc(sizeof(char*) * (counter(s, c) + 1))))
		return (0);
	memallo(counter(s, c), words, s, c);
	fill_words(s, words, c);
	return (words);
}
