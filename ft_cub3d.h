/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:49:37 by mait-si-          #+#    #+#             */
/*   Updated: 2020/01/09 13:52:11 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define BUFFER_SIZE 32
# define WALL 0xffffff
# define PLAYER 0x9b59b6
# define WIN_WIDTH 1600
# define WIN_HIGHT 900

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
	int			r[2];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f[3];
	int			c[3];
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

typedef struct	s_map
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_axis		axis;
	t_mapconf	mapconf;
	t_player	player;
}				t_map;

int				get_next_line(int fd, char **line);
void			sketchmap(t_map *map);
t_map			set_mapconf(char *file);
t_map			check_mapconf(t_map map);
void			drawplayer(t_map map, int r);
t_player		set_player(t_map map);
void			ft_puterror(char *msg);
int				quit(t_map *map);

#endif
