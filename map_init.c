/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:40:26 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 15:53:43 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

unsigned long	get_color(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_puterror("the Colors must have a value between 0 and 255.");
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

char			*get_conf(char *scene, char *lookfor, int i)
{
	char	*line;
	int		fd;

	if ((fd = open(scene, O_RDONLY)) < 0)
		ft_puterror("This scene is not exist.");
	while (get_next_line(fd, &line))
	{
			if (!ft_strcmp(line, "") || *line == '\n')
			continue ;
		else if (!ft_strcmp(lookfor, ft_split(line, ' ')[0]))
			if (*lookfor == 'C' || *lookfor == 'F')
				if (ft_tablen(ft_split(line, ' ')) != 2 ||
				ft_tablen(ft_split(++line, ',')) != 3)
					ft_puterror("Fix F or C data");
				else
					return (ft_split(line, ',')[i]);
			else if (*line == 'R' && ft_tablen(ft_split(line, ' ')) != 3)
				ft_puterror("Fix the resolution data");
			else if (*line != 'R' && ft_tablen(ft_split(line, ' ')) != 2)
				ft_puterror("you have to fix your texture path");
			else
				return (ft_split(line, ' ')[i]);
		else
			continue ;
		free(line);
	}
	free(line);
	ft_puterror("you have to fix your scene.");
	exit(-1);
}

void		set_conf(char *scene)
{
	t_map.conf.r[0] = check_reso('W', ft_atoi(get_conf(scene, "R", 1)));
	t_map.conf.r[1] = check_reso('H', ft_atoi(get_conf(scene, "R", 2)));
	t_map.conf.no = get_conf(scene, "NO", 1);
	t_map.conf.so = get_conf(scene, "SO", 1);
	t_map.conf.we = get_conf(scene, "WE", 1);
	t_map.conf.ea = get_conf(scene, "EA", 1);
	t_map.conf.s = get_conf(scene, "S", 1);
	t_map.conf.f = get_color(
	ft_atoi(get_conf(scene, "F", 0)),
	ft_atoi(get_conf(scene, "F", 1)),
	ft_atoi(get_conf(scene, "F", 2)));
	t_map.conf.c = get_color(
	ft_atoi(get_conf(scene, "C", 0)),
	ft_atoi(get_conf(scene, "C", 1)),
	ft_atoi(get_conf(scene, "C", 2)));
}

int		set_player()
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	i = 0;
	while (t_map.grid[i])
	{
		j = 0;
		x = 0;
		while (t_map.grid[i][j])
		{
			if (t_map.grid[i][j] == 'N' || t_map.grid[i][j] == 'S' || t_map.grid[i][j] == 'W' || t_map.grid[i][j] == 'E')
			{
				t_map.player.y = y + SIZE / 2;
				t_map.player.x = x + SIZE / 2;
				t_map.player.view = t_map.grid[i][j];
				return (1);
			}
			j++;
			x += SIZE;
		}
		y += SIZE;
		i++;
	}
	return (0);
}

void			setup(char *scene)
{
	t_map.mlx_ptr = mlx_init();
	t_map.scene = check_scene(scene);
	set_conf(scene);
	t_map.win_ptr = mlx_new_window(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1], "The Game");
	set_grid();
	set_player();
	if (t_map.player.view == 'N')
		t_map.player.angle = -90;
	if (t_map.player.view == 'E')
		t_map.player.angle = 0;
	if (t_map.player.view == 'S')
		t_map.player.angle = 90;
	if (t_map.player.view == 'W')
		t_map.player.angle = 180;
	draw();
}
