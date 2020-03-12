/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:12:02 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/12 23:28:10 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void		set_grid(void)
{
	char *map;
	char *tmp;

	map = "";
	tmp = map;
	map = ft_strjoin(map, g_map.line);
	free(map);
	map = ft_strjoin(map, "\n");
	free(g_map.line);
	while (get_next_line(g_map.fd, &g_map.line))
	{
		g_map.grid_width = (g_map.grid_width > (int)ft_strlen(g_map.line)) ?
		g_map.grid_width : ft_strlen(g_map.line);
		tmp = map;
		map = ft_strjoin(map, g_map.line);
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		free(g_map.line);
		g_map.grid_height += ft_strlen(g_map.line) > 0 ? 1 : 0;
	}
	g_map.conf.grid = ft_split(map, '\n');
	free(map);
	map = NULL;
}
