/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapshape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:17:46 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/10 11:30:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	**get_mapshape(char *file)
{
	int		fd;
	char	*line;
	int		height;
	int		width;

	height = 0;
	width = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("This file is not exist.");
	while (get_next_line(fd, &line))
	{
		if (*line != '1')
			continue ;
		while (*line)
		{
			if (*line == '1')
				width++;
			line++;
			while (*line == ' ')
				line++;
		}
		height++;
	}
	ft_putnbr(width);
	ft_putstr(", ");
	ft_putnbr(height);
	exit(1);
	return (ft_split(line, '\n'));
}
