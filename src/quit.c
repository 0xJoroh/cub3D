/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:07:15 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/24 15:44:08 by mait-si-         ###   ########.fr       */
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
	free(t_map.conf.ea);
	free(t_map.conf.so);
	free(t_map.conf.we);
	free(t_map.conf.no);
	free(t_map.conf.s);
	freeing(t_map.conf.grid);
	exit(1);
	return (0);
}
