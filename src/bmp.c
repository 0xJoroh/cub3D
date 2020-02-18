/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:47:57 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/18 17:22:32 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	init_bmp(void)
{
	t_map.bmp.width = t_map.conf.r[0];
	t_map.bmp.height = t_map.conf.r[1];
	t_map.bmp.bitcount = 24;
	t_map.bmp.width_in_bytes =
	(t_map.bmp.width * t_map.bmp.bitcount + 31) / 32 * 4;
	t_map.bmp.imagesize = t_map.bmp.width_in_bytes * t_map.bmp.height;
	t_map.bmp.bmp_size = 40;
	t_map.bmp.bfoffbits = 54;
	t_map.bmp.filesize = 54 + t_map.bmp.imagesize;
	t_map.bmp.bi_planes = 1;
	ft_memcpy(t_map.bmp.header, "BM", 2);
	ft_memcpy(t_map.bmp.header + 2, &t_map.bmp.filesize, 4);
	ft_memcpy(t_map.bmp.header + 10, &t_map.bmp.bfoffbits, 4);
	ft_memcpy(t_map.bmp.header + 14, &t_map.bmp.bmp_size, 4);
	ft_memcpy(t_map.bmp.header + 18, &t_map.bmp.width, 4);
	ft_memcpy(t_map.bmp.header + 22, &t_map.bmp.height, 4);
	ft_memcpy(t_map.bmp.header + 26, &t_map.bmp.bi_planes, 2);
	ft_memcpy(t_map.bmp.header + 28, &t_map.bmp.bitcount, 2);
	ft_memcpy(t_map.bmp.header + 34, &t_map.bmp.imagesize, 4);
}

void	bmp(const char *argv)
{
	int				fd;
	unsigned char	*buf;
	int				xy[2];
	int				x2;

	xy[1] = t_map.conf.r[1];
	if (ft_strcmp("––save", argv))
		ft_puterror("your second argument is incorrect");
	init_bmp();
	if (!(buf = (unsigned char	*)malloc(t_map.bmp.imagesize)))
		ft_puterror("There is an error for allocat a space into your memory");
	fd = open("screenshot.bmp", O_RDWR | O_CREAT, 500);
	write(fd, t_map.bmp.header, 54);
	while (--xy[1] >= 0)
	{
		xy[0] = t_map.conf.r[0];
		x2 = 0;
		while (--xy[0] >= 0)
			write(fd, &t_map.img.data[xy[1] * t_map.conf.r[0] + x2++], 3);
	}
	close(fd);
	free(buf);
	quit();
}
