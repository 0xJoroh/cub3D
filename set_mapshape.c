/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapshape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:17:46 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 16:26:16 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		line_counter(char *line)
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

int		get_height(char *scene)
{
	int		height;
	char	*line;
	int		fd;

	height = 1;
	fd = open(scene, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		height++;
	}
	return (height);
}

int		get_width(char *scene)
{
	int		width;
	char	*line;
	int		fd;
	int		i;

	fd = open(scene, O_RDONLY);
	while (get_next_line(fd, &line) && *line != '1')
		continue;
	width = line_counter(line);
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

void	check_map(t_map map)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	end = 0;
	while (map.map[0][end])
		end++;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j] && !i)
			if (map.map[i][j++] != '1')
				ft_puterror("The map must be closed/surrounded by walls.");
		if (map.map[i][0] != '1' || map.map[i][end - 1] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
		i++;
	}
	j = 0;
	while (map.map[i - 1][j])
		if (map.map[i - 1][j++] != '1')
			ft_puterror("The map must be closed/surrounded by walls.");
}

void	set_mapshape(t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(map->scene, O_RDONLY);
	map->map = (char**)malloc((get_height(map->scene) + 1) * sizeof(char*));
	while (get_next_line(fd, &line))
	{
		if (*line != '1' && *line != '0')
			continue ;
		map->map[i] = (char*)malloc(get_width(map->scene) + 1);
		j = 0;
		while (*line)
		{
			while (*line == ' ')
				line++;
			map->map[i][j++] = *line++;
		}
		map->map[i++][j] = '\0';
	}
	map->map[i] = NULL;
}
