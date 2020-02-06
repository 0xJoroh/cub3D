#include "ft_cub3d.h"

void	vision(t_map *map)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	while (i++ <= SIZE)
	{
		x = cos(map->player->angle * M_PI / 180) * i + map->player->axis.x;
		y = sin(map->player->angle * M_PI / 180) * i + map->player->axis.y;
		map->img->data[(int)y * WIN_WIDTH + (int)x] = PLAYER;
	}
}

void		player(t_map *map)
{
	int			x;
	int			y;

	x = map->player->axis.x - 6;
	while (x < map->player->axis.x + 6)
	{
		y = map->player->axis.y - 6;
		while (y < map->player->axis.y + 6)
		{
			if ((pow(x - map->player->axis.x, 2) + pow(y - map->player->axis.y, 2)) <= pow(6, 2))
				map->img->data[y * WIN_WIDTH + x] = PLAYER;
			y++;
		}
		x++;
	}
	vision(map);
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
			map.img->data[y * WIN_WIDTH + x] = WALL_COLOR;
	}
}

void		sketchmap(t_map *map)
{
	int i;
	int j;

	i = 0;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img->img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img->data = (int *)mlx_get_data_addr(map->img->img_ptr, &map->img->bpp, &map->img->size_l, &map->img->endian);
	map->axis->y = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
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
	printf("r[0]: %d\n", map.mapconf->r[0]);
	printf("r[1]: %d\n", map.mapconf->r[1]);
	printf("no: %s\n", map.mapconf->no);
	printf("so: %s\n", map.mapconf->so);
	printf("we: %s\n", map.mapconf->we);
	printf("ea: %s\n", map.mapconf->ea);
	printf("s: %s\n", map.mapconf->s);
	printf("f: %lu\n", map.mapconf->f);
	printf("c: %lu\n", map.mapconf->c);
	printf("player X: %f\n", map.player->axis.x);
	printf("player Y: %f\n", map.player->axis.y);
	printf("vision: %c\n", map.player->vision);
	ft_print_words_tables(map.map);
}
