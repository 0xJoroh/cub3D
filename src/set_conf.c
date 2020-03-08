/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:36:47 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 23:13:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static unsigned long	get_color(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_puterror("the Colors must have a value between 0 and 255.");
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static void				get_conf2(char **words)
{
	if (!ft_strcmp("R", words[0]))
	{
		g_map.conf.r[0] = check_reso('W', ft_atoi(words[1]));
		g_map.conf.r[1] = check_reso('H', ft_atoi(words[2]));
	}
	else if (!ft_strcmp("NO", words[0]))
		g_map.conf.no = ft_strdup(words[1]);
	else if (!ft_strcmp("SO", words[0]))
		g_map.conf.so = ft_strdup(words[1]);
	else if (!ft_strcmp("WE", words[0]))
		g_map.conf.we = ft_strdup(words[1]);
	else if (!ft_strcmp("EA", words[0]))
		g_map.conf.ea = ft_strdup(words[1]);
	else if (!ft_strcmp("S", words[0]))
		g_map.conf.s = ft_strdup(words[1]);
	else
		ft_puterror("There is extra config into your .cub file");
}

static void				get_conf(char **words)
{
	char **str;

	if (!ft_strcmp("F", words[0]))
	{
		str = ft_split(g_map.line + 1, ',');
		g_map.conf.f = get_color(ft_atoi(str[0]),
		ft_atoi(str[1]), ft_atoi(str[2]));
		freeing(str);
	}
	else if (!ft_strcmp("C", words[0]))
	{
		str = ft_split(g_map.line + 1, ',');
		g_map.conf.c = get_color(ft_atoi(str[0]),
		ft_atoi(str[1]), ft_atoi(str[2]));
		freeing(str);
	}
	else
		get_conf2(words);
}

void					set_conf(void)
{
	char	**words;

	while (get_next_line(g_map.fd, &g_map.line))
	{
		if (ft_strcmp(g_map.line, ""))
		{
			words = ft_split(g_map.line, ' ');
			if (words[0][0] == '1')
				set_grid(g_map.grid_width = grid_width(g_map.line));
			else
				get_conf(words);
			freeing(words);
		}
		free(g_map.line);
	}
	free(g_map.line);
}
