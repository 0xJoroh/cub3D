#include "ft_cub3d.h"

void	rander(float x, float y, int color)
{
	if (x < t_map.conf.r[0] && y < t_map.conf.r[1] && x > 0 && y > 0)
		t_map.img.data[(int)y * t_map.conf.r[0] + (int)x] = color;
}

float	degtorad(float deg)
{
	return (deg * M_PI / 180);
}

int		wall_collision(float x, float y)
{
	return (t_map.grid[(int)y / SIZE][(int)x / SIZE] == '1');
}

float	normalize_angle(float angle)
{
	if (angle > 360 || angle < -360)
		return (0);
	return (angle);
}

void	view()
{
	t_map.ray.angle -= 30;
	for (float j = 0 ; j < 60 ; j += (float)60 / WIN_WIDTH)
	{
		t_map.ray.distance = raycast();
		for (int i = 0 ; i < t_map.ray.distance; i++)
		{
			float x = cos(degtorad(t_map.ray.angle)) * i + t_map.player.x;
			float y = sin(degtorad(t_map.ray.angle)) * i + t_map.player.y;
			rander(x, y, PLAYER);
		}
		t_map.ray.angle += (float)60 / WIN_WIDTH;
	}
	t_map.ray.angle -= 30;
}

// void	view()
// {
// 	float	x;
// 	float	y;

// 	// t_map.ray.distance = 100;
// 	t_map.ray.distance = raycast();

// 	for (int i = 0; i < t_map.ray.distance; i++)
// 	{
// 		x = cos(degtorad(t_map.ray.angle)) * i + t_map.player.x;
// 		y = sin(degtorad(t_map.ray.angle)) * i + t_map.player.y;
// 		rander(x, y, PLAYER);
// 	}
// }

void		player()
{
	int x = t_map.player.x - 6;
	while (x < t_map.player.x + 6)
	{
		int y = t_map.player.y - 6;
		while (y < t_map.player.y + 6)
		{
			if ((pow(x - t_map.player.x, 2) + pow(y - t_map.player.y, 2)) <= pow(6, 2))
				rander(x, y, PLAYER);
			y++;
		}
		x++;
	}
}

void		squar()
{
	int		y;
	int		x;

	y = t_map.y - 1;

	while (++y < SIZE + t_map.y)
	{
		x = t_map.x - 1;
		while (++x < SIZE + t_map.x)
			rander(x, y, WALL_COLOR);
	}
}

void		map()
{
	t_map.y = 0;
	for (int i = 0 ; t_map.grid[i] ; i++)
	{
		for (int j = 0; t_map.grid[i][j]; j++)
		{
			if (t_map.grid[i][j] == '1')
				squar();
			t_map.x += SIZE;
		}
		t_map.x = 0;
		t_map.y += SIZE;
	}
}

void		draw()
{
	t_map.img.img_ptr = mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr, &t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
	map();
	ray_init();
	view();
	player();
	mlx_put_image_to_window(t_map.mlx_ptr, t_map.win_ptr, t_map.img.img_ptr, 0, 0);
}
