/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:49:37 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/14 14:44:01 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define BUFFER_SIZE 32
# define WALL_COLOR 0xffffff
# define PLAYER 0x9b59b6
# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define SIZE 55

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct	s_mapconf
{
	int				r[2];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned long	f;
	unsigned long	c;
}				t_mapconf;

typedef	struct	s_axis
{
	int			x;
	int			y;
}				t_axis;

typedef struct	s_player
{
	char		vision;
	t_axis		axis;
}				t_player;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_map
{
	char		*scene;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_axis		axis;
	t_mapconf	mapconf;
	t_player	player;
	t_img		*img;
}				t_map;

int				get_next_line(int fd, char **line);
void			sketchmap(t_map map);
void			set_mapconf(char *scene, t_map *map);
void			set_player(t_map *map);
void			ft_puterror(char *msg);
int				quit(t_map *map);
void			set_mapshape(t_map *map);
void			check_walls(t_map map);
char			*check_scene(char *scene);
int				check_reso(char c, int res);
void			check_mapshape(t_map map);
void			drawplayer(t_map map);
void			drawsquar(t_map map);

#endif
