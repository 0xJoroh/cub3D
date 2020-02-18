/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:24:33 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/17 15:24:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
void	bmp(const char *argv)
{
	if (ft_strcmp("––save", argv))
		ft_puterror("your second argument is incorrect");
	//width, height, and bitcount are the key factors:
    int width = 2;
    int height = 2;
    int bitcount = 24;//<- 24-bit bitmap

    //take padding in to account
    int width_in_bytes = floor((width * bitcount + 31) / 32) * 4;

    //total image size in bytes, not including header
    int imagesize = width_in_bytes * height;

    //this value is always 40, it's the sizeof(BITMAPINFOHEADER)
    const int biSize = 40;

    //bitmap bits start after headerfile,
    //this is sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
    const int bfOffBits = 54;

    //total file size:
    int filesize = 54 + imagesize;

    //number of planes is usually 1
    const int biPlanes = 1;

    //create header:
    //copy to buffer instead of BITMAPFILEHEADER and BITMAPINFOHEADER
    //to avoid problems with structure packing
    unsigned char header[54];
    ft_memcpy(header, "BM", 2);
    ft_memcpy(header + 2 , &filesize, 4);
    ft_memcpy(header + 10, &bfOffBits, 4);
    ft_memcpy(header + 14, &biSize, 4);
    ft_memcpy(header + 18, &width, 4);
    ft_memcpy(header + 22, &height, 4);
    ft_memcpy(header + 26, &biPlanes, 2);
    ft_memcpy(header + 28, &bitcount, 2);
    ft_memcpy(header + 34, &imagesize, 4);

    //prepare pixel data:
    unsigned char* buf = malloc(imagesize);
    for(int row = height - 1; row >= 0; row--)
    {
        for(int col = 0; col < width; col++)
        {
            buf[row * width_in_bytes + col * 3 + 0] = 255;//blue
            buf[row * width_in_bytes + col * 3 + 1] = 0;//green
            buf[row * width_in_bytes + col * 3 + 2] = 0;//red
        }
    }

    FILE *fout = fopen("test.bmp", "wb");
    fwrite(header, 1, 54, fout);
    fwrite((char*)buf, 1, imagesize, fout);
    fclose(fout);
    free(buf);
	// row_size = floor((bpp * t_map.conf.r[0] + 31) / 32) * 4
}

int		main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
		ft_puterror("you have to pass a map in arguments");
	if (argc == 3)
		bmp(argv[2]);
	setup(argv[1]);
	mlx_hook(t_map.win_ptr, 2, 0, key_press, (void*)0);
	mlx_hook(t_map.win_ptr, 3, 0, key_releas, (void*)0);
	mlx_hook(t_map.win_ptr, 17, 0, quit, (void*)0);
	mlx_loop_hook(t_map.mlx_ptr, key_event, (void*)0);
	mlx_loop(t_map.mlx_ptr);
	return (0);
}
