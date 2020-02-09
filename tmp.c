#include "ft_cub3d.h"

void	rander(float x, float y, int color)
{
	if (x < t_map.conf.r[0] && y < t_map.conf.r[1] && x > 0 && y > 0)
		t_map.img.data[(int)y * t_map.conf.r[0] + (int)x] = color;
}

float	degtorad(float deg)
{
	return (deg * (M_PI / 180));
}

float	radtodeg(float rad)
{
	return (rad * (180 / M_PI));
}

int		wall_collision(float x, float y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (t_map.grid[0][i])
		i++;
	while (t_map.grid[j])
		j++;
	if (x > 0 && y > 0)
		if ((int)y / SIZE < j && (int)x / SIZE < i)
			return (t_map.grid[(int)y / SIZE][(int)x / SIZE] == '1');
	return (1);
}

float	normalize_angle(float angle)
{
	angle = (float)fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}







void		draw()
{
	t_map.img.img_ptr = mlx_new_image(t_map.mlx_ptr, t_map.conf.r[0], t_map.conf.r[1]);
	t_map.img.data = (int *)mlx_get_data_addr(t_map.img.img_ptr, &t_map.img.bpp, &t_map.img.size_l, &t_map.img.endian);
	map();
	view();
	player();
	mlx_put_image_to_window(t_map.mlx_ptr, t_map.win_ptr, t_map.img.img_ptr, 0, 0);
}





















void	view()
{
	// float a,b,c;
	float angle = t_map.ray.angle - FOV_ANGLE / 2;
	angle = normalize_angle(angle);
	for (int j = 0 ; j < t_map.conf.r[0] ; j++)
	{
		ray_init(angle);

		t_map.ray.distance = raycast(angle);
		for (int i = 0 ; i < t_map.ray.distance; i++)
		{
			float x = cos(angle) * i + t_map.player.x;
			float y = sin(angle) * i + t_map.player.y;
			rander(x, y, PLAYER);
		}
		angle += FOV_ANGLE / t_map.conf.r[0];
	}
}

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
