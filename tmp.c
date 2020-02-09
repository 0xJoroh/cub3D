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
	if (angle > (2 * M_PI) || angle < -(2 * M_PI))
		return (0);
	return (angle);
}

void	view()
{
	float	x;
	float	y;
	t_map.ray.angle -= degtorad(30);
	for (float j = 0 ; j < 60 ; j += (float)60 / WIN_WIDTH)
	{
		t_map.ray.distance = raycast();
		for (int i = 0 ; i < t_map.ray.distance; i++)
		{
			x = cos(t_map.ray.angle) * i + t_map.player.x;
			y = sin(t_map.ray.angle) * i + t_map.player.y;
			rander(x, y, PLAYER);
		}
		t_map.ray.angle += degtorad((float)60 / WIN_WIDTH);
	}
	t_map.ray.angle -= degtorad(30);
}

// void	view()
// {
// 	float	x;
// 	float	y;
// 	t_map.ray.distance = raycast();

// 	for (int i = 0; i < t_map.ray.distance; i++)
// 	{
// 		x = cos(t_map.ray.angle) * i + t_map.player.x;
// 		y = sin(t_map.ray.angle) * i + t_map.player.y;
// 		rander(x, y, PLAYER);
// 	}
// }

void		player()
{
	int			x;
	int			y;

	view();
	x = t_map.player.x - 6;
	while (x < t_map.player.x + 6)
	{
		y = t_map.player.y - 6;
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

void		matrix()
{
	for (int y = 0; y < WIN_WIDTH; y += SIZE)
		for (int x = 0; x < WIN_HEIGHT; x++)
			rander(y, x, PLAYER);
}

void		draw()
{
	ray_init();
	t_map.img.img_ptr = mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr, &t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
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
	player();
	// matrix();
	mlx_put_image_to_window(t_map.mlx_ptr, t_map.win_ptr, t_map.img.img_ptr, 0, 0);
}

void		ft_putstruct()
{
	printf("scene: %s\n", t_map.scene);
	printf("Map X: %f\n", t_map.x);
	printf("Map Y: %f\n", t_map.y);
	printf("r[0]: %d\n", t_map.conf.r[0]);
	printf("r[1]: %d\n", t_map.conf.r[1]);
	printf("no: %s\n", t_map.conf.no);
	printf("so: %s\n", t_map.conf.so);
	printf("we: %s\n", t_map.conf.we);
	printf("ea: %s\n", t_map.conf.ea);
	printf("s: %s\n", t_map.conf.s);
	printf("f: %lu\n", t_map.conf.f);
	printf("c: %lu\n", t_map.conf.c);
	printf("player X: %f\n", t_map.player.x);
	printf("player Y: %f\n", t_map.player.y);
	printf("view: %c\n", t_map.player.view);
	ft_print_words_tables(t_map.grid);
}
