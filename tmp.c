#include "ft_cub3d.h"

void	putpx(float x, float y, int color, t_map *map)
{
	if (x <= map->conf->r[0] && y <= map->conf->r[1])
		if (x >= 0 && y >= 0)
			map->img->data[(int)y * map->conf->r[0] + (int)x] =color;
}

void	vision(t_map *map)
{
	int		i;
	float		j;
	float	x;
	float	y;

	j = 0;
	map->player->angle -= 30;
	while (j < 60)
	{
		i = 0;
		while (i++ <= 50)
		{
			x = cos(map->player->angle * M_PI / 180) * i + map->player->axis.x;
			y = sin(map->player->angle * M_PI / 180) * i + map->player->axis.y;
			putpx(x, y, WALL_COLOR, map);
		}
		map->player->angle += (float)60 / WIN_WIDTH;
		j+= (float)60 / WIN_WIDTH;
	}
	map->player->angle -= 30;
	// printf("%f, %f\n", map->player->axis.x, map->player->axis.y);
}

// void	vision(t_map *map)
// {
// 	int		i;
// 	float	x;
// 	float	y;

// 	i = 0;
// 	while (i++ <= raycast(map))
// 	{
// 		x = cos(map->player->angle * M_PI / 180) * i + map->player->axis.x;
// 		y = sin(map->player->angle * M_PI / 180) * i + map->player->axis.y;
// 		map->img->data[(int)y * map->conf->r[0] + (int)x] = PLAYER;
// 	}
// }

void		player(t_map *map)
{
	int			x;
	int			y;

	vision(map);
	x = map->player->axis.x - 6;
	while (x < map->player->axis.x + 6)
	{
		y = map->player->axis.y - 6;
		while (y < map->player->axis.y + 6)
		{
			if ((pow(x - map->player->axis.x, 2) + pow(y - map->player->axis.y, 2)) <= pow(6, 2))
				putpx(x, y, PLAYER, map);
			y++;
		}
		x++;
	}
}

void		squar(t_map map)
{
	int		y;
	int		x;

	y = map.axis->y - 1;

	while (++y < SIZE + map.axis->y)
	{
		x = map.axis->x - 1;
		while (++x < SIZE + map.axis->x)
			putpx(x, y, WALL_COLOR, &map);
	}
}

void		draw(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->img->img_ptr = mlx_new_image(map->mlx_ptr, map->conf->r[0], map->conf->r[1]);
	map->img->data = (int *)mlx_get_data_addr(map->img->img_ptr, &map->img->bpp, &map->img->size_l, &map->img->endian);
	map->axis->y = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '1')
				squar(*map);
			map->axis->x += SIZE;
			j++;
		}
		map->axis->x = 0;
		map->axis->y += SIZE;
		i++;
	}
	player(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img->img_ptr, 0, 0);
}

void		ft_putstruct(t_map map)
{
	printf("scene: %s\n", map.scene);
	printf("Map X: %f\n", map.axis->x);
	printf("Map Y: %f\n", map.axis->y);
	printf("r[0]: %d\n", map.conf->r[0]);
	printf("r[1]: %d\n", map.conf->r[1]);
	printf("no: %s\n", map.conf->no);
	printf("so: %s\n", map.conf->so);
	printf("we: %s\n", map.conf->we);
	printf("ea: %s\n", map.conf->ea);
	printf("s: %s\n", map.conf->s);
	printf("f: %lu\n", map.conf->f);
	printf("c: %lu\n", map.conf->c);
	printf("player X: %f\n", map.player->axis.x);
	printf("player Y: %f\n", map.player->axis.y);
	printf("vision: %c\n", map.player->vision);
	ft_print_words_tables(map.grid);
}
