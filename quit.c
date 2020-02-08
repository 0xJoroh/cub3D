/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:07:15 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/08 20:13:05 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_puterror(char *msg)
{
	write(2, "Error\n", 7);
	ft_putstr(msg);
	quit();
}

int		quit()
{
	// while (t_map.grid_height--)
	// 	free(t_map.grid[t_map.grid_height]);
	// free(t_map.grid);
	exit(1);
	return (0);
}
