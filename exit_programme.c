/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_programme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:07:15 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/14 11:37:49 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_puterror(char *msg)
{
	write(2, "Error\n", 7);
	ft_putstr(msg);
	exit(-1);
}

int		quit(t_map *map)
{
	(void)map;
	free(map);
	exit(1);
}
