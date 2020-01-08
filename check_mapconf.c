/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapconf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:57:18 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/08 12:07:27 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

// void	check_map(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;

// 	i = 0;
// 	fd = open("map.cub", O_RDONLY);
// 	if (fd < 0)
// 		ft_puterror("file descriptor is undifined");
// 	while (get_next_line(fd, &line))
// 		if (ft_isdigit(*line) && *line != '1')
// 			ft_puterror("map config not good");
// 		else if (ft_isdigit(*line) && *line == '1')
// 			if (i++ == 0)
// 				while (*line)
// 					if (*line != '1')
// 						ft_puterror("map config not good");
// }

t_map	check_mapconf(t_map map)
{
	if (map.mapconf.r[0] > 1600 || map.mapconf.r[1] > 900)
	{
		map.mapconf.r[0] = 1600;
		map.mapconf.r[1] = 900;
	}
	if (map.mapconf.r[0] <= 0 || map.mapconf.r[1] <= 0)
		ft_puterror("the resolution must have a positive value.");
	if (map.mapconf.f[0] > 255 || map.mapconf.f[1] > 255
	|| map.mapconf.f[2] > 255 || map.mapconf.f[0] < 0 ||
	map.mapconf.f[1] < 0 || map.mapconf.f[2] < 0)
		ft_puterror("the Floor Color must have a value between 0 and 255.");
	if (map.mapconf.c[0] > 255 || map.mapconf.c[1] > 255
	|| map.mapconf.c[2] > 255 || map.mapconf.c[0] < 0 ||
	map.mapconf.c[1] < 0 || map.mapconf.c[2] < 0)
		ft_puterror("the Celling Color must have a value between 0 and 255.");
	if (map.mapconf.f[0] == map.mapconf.c[0] &&
	map.mapconf.f[1] == map.mapconf.c[1] &&
	map.mapconf.f[2] == map.mapconf.c[2])
		ft_puterror("The celling and the floor colors must be deffirent");
	// check_map();
	return (map);
}
