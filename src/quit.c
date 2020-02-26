/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:07:15 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/25 16:30:12 by mait-si-         ###   ########.fr       */
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
	mlx_destroy_window(t_map.mlx_ptr, t_map.win_ptr);
	exit(1);
	return (0);
}
