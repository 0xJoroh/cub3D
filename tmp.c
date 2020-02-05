#include "ft_cub3d.h"

void		drawplayer(t_map *map)
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
}

void		drawsquar(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y++ <= SIZE)
	{
		x = 0;
		while (x++ <= SIZE)
			map->img->data[map->axis->y * WIN_WIDTH + map->axis->x++] = WALL_COLOR;
		map->axis->y++;
		map->axis->x -= SIZE;
	}
}

void		sketchmap(t_map *map)
{
	while (*map->map)
	{
		while (**map->map)
		{
			// if (**map->map == '1')
				// drawsquar(map);
			map->axis->x += SIZE;
			(*map->map)++;
		}
		map->axis->x = 0;
		map->axis->y += SIZE;
		map->map++;
	}
	drawplayer(map);
}

void		ft_putstruct(t_map map)
{
	printf("scene: %s\n", map.scene);
	printf("Map X: %d\n", map.axis->x);
	printf("Map Y: %d\n", map.axis->y);
	printf("r[0]: %d\n", map.mapconf->r[0]);
	printf("r[1]: %d\n", map.mapconf->r[1]);
	printf("no: %s\n", map.mapconf->no);
	printf("so: %s\n", map.mapconf->so);
	printf("we: %s\n", map.mapconf->we);
	printf("ea: %s\n", map.mapconf->ea);
	printf("s: %s\n", map.mapconf->s);
	printf("f: %lu\n", map.mapconf->f);
	printf("c: %lu\n", map.mapconf->c);
	printf("player X: %d\n", map.player->axis.x);
	printf("player Y: %d\n", map.player->axis.y);
	printf("vision: %c\n", map.player->vision);
	ft_print_words_tables(map.map);
}
