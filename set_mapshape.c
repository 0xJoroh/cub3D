/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapshape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:17:46 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 14:26:13 by mait-si-         ###   ########.fr       */
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

int		get_height(char *file)
{
	int		height;
	char	*line;
	int		fd;

	height = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		height++;
	}
	return (height);
}

int		get_width(char *file)
{
	int		width;
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
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
	if (line_counter(line) != width)
		ft_puterror("Fix your Map");
	return (width);
}

void	set_mapshape(t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(map->file, O_RDONLY);
	map->map = (char**)malloc((get_height(map->file) + 1) * sizeof(char*));
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		map->map[i] = (char*)malloc(get_width(map->file) + 1);
		j = 0;
		while (*line)
			if (*line == ' ')
			{
				line++;
				continue ;
			}
			else
				map->map[i][j++] = *line++;
		map->map[i++][j] = '\0';
	}
	map->map[i] = NULL;
}
