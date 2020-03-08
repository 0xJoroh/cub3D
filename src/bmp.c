/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:47:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 23:13:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	init_bmp(void)
{
	g_map.bmp.width = g_map.conf.r[0];
	g_map.bmp.height = g_map.conf.r[1];
	g_map.bmp.bitcount = 24;
	g_map.bmp.width_in_bytes =
	(g_map.bmp.width * g_map.bmp.bitcount + 31) / 32 * 4;
	g_map.bmp.imagesize = g_map.bmp.width_in_bytes * g_map.bmp.height;
	g_map.bmp.bmp_size = 40;
	g_map.bmp.bfoffbits = 54;
	g_map.bmp.filesize = 54 + g_map.bmp.imagesize;
	g_map.bmp.bi_planes = 1;
	ft_memcpy(g_map.bmp.header, "BM", 2);
	ft_memcpy(g_map.bmp.header + 2, &g_map.bmp.filesize, 4);
	ft_memcpy(g_map.bmp.header + 10, &g_map.bmp.bfoffbits, 4);
	ft_memcpy(g_map.bmp.header + 14, &g_map.bmp.bmp_size, 4);
	ft_memcpy(g_map.bmp.header + 18, &g_map.bmp.width, 4);
	ft_memcpy(g_map.bmp.header + 22, &g_map.bmp.height, 4);
	ft_memcpy(g_map.bmp.header + 26, &g_map.bmp.bi_planes, 2);
	ft_memcpy(g_map.bmp.header + 28, &g_map.bmp.bitcount, 2);
	ft_memcpy(g_map.bmp.header + 34, &g_map.bmp.imagesize, 4);
}

void	bmp(const char *argv)
{
	int				fd;
	unsigned char	*buf;
	int				xy[2];
	int				x2;

	xy[1] = g_map.conf.r[1];
	if (ft_strcmp("––save", argv))
		ft_puterror("your second argument is incorrect");
	init_bmp();
	if (!(buf = (unsigned char	*)malloc(g_map.bmp.imagesize)))
		ft_puterror("There is an error for allocat a space into your memory");
	fd = open("screenshot.bmp", O_RDWR | O_CREAT, 500);
	write(fd, g_map.bmp.header, 54);
	while (--xy[1] >= 0)
	{
		xy[0] = g_map.conf.r[0];
		x2 = 0;
		while (--xy[0] >= 0)
			write(fd, &g_map.img.data[xy[1] * g_map.conf.r[0] + x2++], 3);
	}
	close(fd);
	free(buf);
	quit();
}
