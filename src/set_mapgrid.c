/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:12:02 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/18 17:22:32 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

static int	valid(char *str)
{
	if (str[0] == 'R' || (str[0] == 'N' && str[1] == 'O') ||
	(str[0] == 'S' && str[1] == 'O') || (str[0] == 'W' && str[1] == 'E')
	|| (str[0] == 'E' && str[1] == 'A') || str[0] == 'S' ||
	str[0] == 'F' || str[0] == 'C' || str[0] == '1' || str[0] == '\0' ||
	str[0] == '0')
		return (1);
	return (0);
}

static int	line_counter(char *line)
{
	int		len;

	len = 0;
	while (*line)
		if (*line++ == ' ')
			continue ;
		else
			len++;
	return (len);
}

static int	get_height(char *scene)
{
	int		height;
	char	*line;
	int		fd;

	height = 1;
	fd = open(scene, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!valid(line))
			ft_puterror("there is extra config on your scene.");
		if (*line != '1')
			continue ;
		height++;
	}
	return (height);
}

static int	get_width(char *scene)
{
	int		width;
	char	*line;
	int		fd;
	int		i;

	fd = open(scene, O_RDONLY);
	while (get_next_line(fd, &line) && *line != '1')
	{
		free(line);
		continue;
	}
	width = line_counter(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (*line)
			if (*line++ == ' ')
				continue ;
			else
				i++;
		if (i != width)
			ft_puterror("Fix your Map");
	}
	return (width);
}

void		set_grid(void)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(t_map.scene, O_RDONLY);
	t_map.grid = (char**)malloc((get_height(t_map.scene) + 1) * sizeof(char*));
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		t_map.grid[i] = (char*)malloc(get_width(t_map.scene) + 1);
		j = 0;
		while (*line)
		{
			while (*line == ' ')
				line++;
			t_map.grid[i][j++] = *line++;
		}
		t_map.grid[i++][j] = '\0';
	}
	t_map.grid[i] = NULL;
	check_walls();
	check_grid();
}
