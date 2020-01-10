/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapshape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:17:46 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 13:31:43 by mait-si-         ###   ########.fr       */
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
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("This file is not exist.");
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

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("This file is not exist.");
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

char	**get_mapshape(char *file)
{
	int		fd;
	char	*line;
	// char	**mapshape;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("This file is not exist.");
	// mapshape = ft_calloc(get_height(file), 1);
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
	}
	ft_putnbr(get_width(file));
	ft_putstr(", ");
	ft_putnbr(get_height(file));
	exit(1);
	return (ft_split(line, '\n'));
}
