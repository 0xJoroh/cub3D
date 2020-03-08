/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:07:15 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 23:13:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_puterror(char *msg)
{
	write(2, "\nError\n", 8);
	ft_putstr(msg);
	quit();
}

int		quit(void)
{
	mlx_destroy_window(g_map.mlx_ptr, g_map.win_ptr);
	exit(1);
	return (0);
}
