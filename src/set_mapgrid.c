/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:12:02 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 23:13:07 by mait-si-         ###   ########.fr       */
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
	fd = open(g_map.scene, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!valid(line))
			ft_puterror("there is extra config on your scene.");
		if (*line == '1')
			height++;
		free(line);
	}
	free(line);
	g_map.grid_height = height - 1;
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

static void	fill_grid(int i, int len)
{
	int j;
	int k;

	j = 0;
	k = 0;
	g_map.conf.grid[i] = (char*)malloc(len + 1);
	while (g_map.line[k])
	{
		while (g_map.line[k] == ' ')
			k++;
		g_map.conf.grid[i][j++] = g_map.line[k++];
	}
	g_map.conf.grid[i][j] = '\0';
}

void		set_grid(int len)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	g_map.conf.grid = (char**)malloc((grid_height() + 1) * sizeof(char*));
	g_map.conf.grid[0] = (char*)malloc(len + 1);
	while (g_map.line[k])
	{
		while (g_map.line[k] == ' ')
			k++;
		g_map.conf.grid[0][i++] = g_map.line[k++];
	}
	g_map.conf.grid[0][i] = '\0';
	free(g_map.line);
	i = 1;
	while (get_next_line(g_map.fd, &g_map.line))
	{
		if (grid_width(g_map.line) != len)
			ft_puterror("fix your map config");
		fill_grid(i++, len);
		free(g_map.line);
	}
	g_map.conf.grid[i] = NULL;
}
