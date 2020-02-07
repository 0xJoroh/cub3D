/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:49:37 by mait-si-          #+#    #+#             */
/*   Updated: 2020/02/07 20:54:41 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define BUFFER_SIZE 128
# define WALL_COLOR 0xffffff
# define PLAYER 0x9b59b6
# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define SIZE 55
# define PLAYER_SPEED 5
# define ROTATION_SPEED 5

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef	struct	s_key
{
	int			left;
	int			right;
	int			forward;
	int			backward;
	int			quit;
	int			left_view;
	int			right_view;
}				t_key;

typedef struct	s_conf
{
	int				r[2];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned long	f;
	unsigned long	c;
}				t_conf;

typedef struct	s_player
{
	char		view;
	float		angle;
	float		x;
	float		y;
}				t_player;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

struct			s_map
{
	float		x;
	float		y;
	char		*scene;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**grid;
	int			grid_height;
	t_conf		conf;
	t_player	player;
	t_img		img;
	t_key		key;
}				t_map;

int				get_next_line(int fd, char **line);
void			setup(char *scene);
void			ft_puterror(char *msg);
int				quit();
void			set_grid();
void			check_walls();
char			*check_scene(char *scene);
int				check_reso(char c, int res);
void			check_grid();
int				key_event();
int				key_releas(int keycode);
int				key_press(int keycode);
int				raycast();

/***********************		Tmp		****************************/

void			draw();
void			player();
void			squar();
void			ft_putstruct();
void			view();

#endif
