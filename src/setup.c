/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:16:54 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/21 16:39:00 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static unsigned long	get_color(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_puterror("the Colors must have a value between 0 and 255.");
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int				set_player(void)
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	i = 0;
	while (t_map.conf.grid[i])
	{
		j = 0;
		x = 0;
		while (t_map.conf.grid[i][j])
		{
			if (get_player(i, j, x, y))
				return (1);
			j++;
			x += SIZE;
		}
		y += SIZE;
		i++;
	}
	return (0);
}

static void				get_conf(char **words)
{
	if (!ft_strcmp("R", words[0]))
	{
		t_map.conf.r[0] = check_reso('W', ft_atoi(words[1]));
		t_map.conf.r[1] = check_reso('W', ft_atoi(words[2]));
	}
	else if (!ft_strcmp("NO", words[0]))
		t_map.conf.no = words[1];
	else if (!ft_strcmp("SO", words[0]))
		t_map.conf.so = words[1];
	else if (!ft_strcmp("WE", words[0]))
		t_map.conf.we = words[1];
	else if (!ft_strcmp("EA", words[0]))
		t_map.conf.ea = words[1];
	else if (!ft_strcmp("S", words[0]))
		t_map.conf.s = words[1];
	else if (!ft_strcmp("F", words[0]))
		t_map.conf.f = get_color(ft_atoi(ft_split(t_map.line + 1, ',')[0]),
			ft_atoi(ft_split(t_map.line + 1, ',')[1]),
			ft_atoi(ft_split(t_map.line + 1, ',')[2]));
	else if (!ft_strcmp("C", words[0]))
		t_map.conf.c = get_color(ft_atoi(ft_split(t_map.line + 1, ',')[0]),
			ft_atoi(ft_split(t_map.line + 1, ',')[1]),
			ft_atoi(ft_split(t_map.line + 1, ',')[2]));
	else if ('1' == words[0][0])
		set_grid();
}

static void				set_conf(void)
{
	char	**words;

	while (get_next_line(t_map.fd, &t_map.line))
	{
		words = ft_split(t_map.line, ' ');
		if (words)
			get_conf(words);
		free(words);
		free(t_map.line);
	}
	free(t_map.line);
}

void					setup(char *scene)
{
	t_map.mlx_ptr = mlx_init();
	t_map.scene = check_scene(scene);
	set_conf();
	t_map.win_ptr = mlx_new_window(t_map.mlx_ptr, t_map.conf.r[0],
	t_map.conf.r[1], "The Game");
	set_player();
	textures_init();
	draw();
}
