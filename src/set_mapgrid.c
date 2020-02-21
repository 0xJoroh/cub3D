/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:12:02 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/21 16:25:07 by mait-si-         ###   ########.fr       */
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

static int	grid_height(void)
{
	int		height;
	char	*line;
	int		fd;

	height = 1;
	fd = open(t_map.scene, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!valid(line))
			ft_puterror("there is extra config on your scene.");
		if (*line == '1')
			height++;
		free(line);
	}
	free(line);
	return (height);
}

int			grid_width(char *str)
{
	int len;

	len = 0;
	while (*str)
		if (*str++ != ' ')
			len++;
	return (len);
}

void		set_grid(void)
{
	int		i;
	int		j;
	int		len;
	int		k;

	i = 0;
	len = grid_width(t_map.line);
	free(t_map.line);
	t_map.conf.grid = (char**)malloc((grid_height() + 1) * sizeof(char*));
	while (get_next_line(t_map.fd, &t_map.line))
	{
		j = 0;
		k = 0;
		if (grid_width(t_map.line) != len)
			ft_puterror("fix your map size");
		t_map.conf.grid[i] = (char*)malloc(len + 1);
		while (t_map.line[k])
		{
			while (t_map.line[k] == ' ')
				k++;
			t_map.conf.grid[i][j++] = t_map.line[k++];
		}
		t_map.conf.grid[i++][j] = '\0';
		free(t_map.line);
	}
	t_map.conf.grid[i] = NULL;
}
